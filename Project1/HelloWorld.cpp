#include "pch.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h> 
#include "HelloWorld.h"
#include <iostream>
#include <string>
#include <ifc2x3/SPFReader.h>
#include <ifc2x3/SPFWriter.h>
#include <ifc2x3/ExpressDataSet.h>
#include <ifc2x3/IfcProject.h>
#include <ifc2x3/IfcLocalPlacement.h>
#include <ifc2x3/IfcAxis2Placement.h>
#include <ifc2x3/IfcAxis2Placement2D.h>
#include <ifc2x3/IfcAxis2Placement3D.h>
#include "CreateConstructionPointVisitor.h"
#include "ComputePlacementVisitor.h"

#include "arxHeaders.h"
#include <sstream>
#include <fstream>

#include <Step/CallBack.h>

//#include <delayimp.h>
//#pragma comment(lib, "delayimp")


void initApp()
{
    // register a command with the AutoCAD command mechanism
    acedRegCmds->addCommand(_T("HELLOWORLD_COMMANDS"),
        _T("Hello"),
        _T("Bonjour"),
        ACRX_CMD_TRANSPARENT,
        helloWorld);

    acedRegCmds->addCommand(_T("TEST_COMMANDS"),
        _T("Test"),
        _T("Test"),
        ACRX_CMD_TRANSPARENT,
        main);

}

void unloadApp()
{
    acedRegCmds->removeGroup(_T("HELLOWORLD_COMMANDS"));
    acedRegCmds->removeGroup(_T("TEST_COMMANDS"));

}

void helloWorld()
{
    acutPrintf(_T("\nHello World!"));

}

const wchar_t* GetWC(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);

    return wc;
}

void main()
{
    AcDbObjectId transId;
    TCHAR* fname;

    struct resbuf* rb;
    // Get a ifc file from the user.
    //
    rb = acutNewRb(RTSTR);
    int stat = acedGetFileD(_T("Pick a IFC file"), NULL, _T("ifc"), 0, rb);
    if ((stat != RTNORM) || (rb == NULL))
    {
        acutPrintf(_T("\nYou must pick a ifc file."));
        return;
    }
    fname = (TCHAR*)acad_malloc((_tcslen(rb->resval.rstring) + 1) * sizeof(TCHAR));
    _tcscpy(fname, rb->resval.rstring);
    acutRelRb(rb);

    acutPrintf(_T("Simple read/write example of Ifc2x3 SDK\n "));
    int argc = 2;

    if (argc < 2)
    {
        acutPrintf(_T("no ifc file to read in command line .\n "));
        //return 1;
    }

    bool inMemory = true;
    if (argc < 4)
    {
        inMemory = false;
    }
    
    // ** open, load, close the file
    std::ifstream ifcFile;
    ifcFile.open(fname);

    ifc2x3::SPFReader reader;
    //ConsoleCallBack cb;
    //reader.setCallBack(&cb);

    if (ifcFile.is_open())
    {
        acutPrintf(_T("reading file ...\n "));
    }
    else
    {
        acutPrintf(_T("ERROR: failed to open\n "));
        //return 1;
    }

    // get length of file
    ifcFile.seekg(0, ifcFile.end);
    std::ifstream::pos_type length = ifcFile.tellg();
    ifcFile.seekg(0, ifcFile.beg);

    bool result = reader.read(ifcFile, inMemory ? length : (std::ifstream::pos_type)0);
    ifcFile.close();

    if (result)
        acutPrintf(_T("OK!!\n"));
    else
    {
        acutPrintf(_T("Ho no, there is a PROBLEM!!\n"));
        std::vector<std::string> errors = reader.errors();
        std::vector<std::string>::iterator it = errors.begin();
        while (it != errors.end())
        {
            std::cout << *it << std::endl;
            ++it;
        }

        //return 1;
    }

    // ** get the model
    ifc2x3::ExpressDataSet* expressDataSet = dynamic_cast<ifc2x3::ExpressDataSet*>(reader.getExpressDataSet());

    if (expressDataSet == NULL)
    {
        acutPrintf(_T("Ho no ... there is no ExpressDataSet.\n"));
        //return (2);
    }

    if (argc > 2)
    {
        // ** Instantiate the model if we want to write it
        expressDataSet->instantiateAll(/*&cb*/);
    }
    // ** Check the root of the model
    Step::RefLinkedList< ifc2x3::IfcProject > projects = expressDataSet->getAllIfcProject();
    if (projects.size() == 0) {
        acutPrintf(_T("Strange ... there is no IfcProject\n"));
    }
    else if (projects.size() > 1) {
        acutPrintf(_T("Strange ... there more than one IfcProject\n"));
    }
    else {
        Step::RefPtr< ifc2x3::IfcProject > project = &*(projects.begin());
        std::string test = project->getName().toISO_8859(Step::String::Western_European);
        acutPrintf(_T("Project name is: %s\n"), GetWC(test.c_str()));
        if (Step::isUnset(project->getLongName().toISO_8859(Step::String::Western_European))) 
        {
            project->setLongName("Je lui donne le nom que je veux");
        }
        acutPrintf(_T("Project long name is: %s\n"), GetWC(project->getLongName().toISO_8859(Step::String::Western_European).c_str()));
    }

    //std::list<Vec3> _points;

    Step::RefLinkedList< ifc2x3::IfcWallStandardCase > wallStandardCases = expressDataSet->getAllIfcWallStandardCase();
    auto idwall = wallStandardCases.begin()->getKey();
    Step::RefPtr<ifc2x3::IfcWallStandardCase> wallStandardCase1 = expressDataSet->getIfcWallStandardCase(idwall);

    /*auto it = wallStandardCases.begin();
    Step::RefPtr< ifc2x3::IfcWallStandardCase > wallStandardCase = &*(it++++++);

    Step::RefPtr<ifc2x3::IfcProductDefinitionShape> ProductDefinitionWall = expressDataSet->getIfcProductDefinitionShape(wallStandardCase->getRepresentation()->getKey());
    auto ShapeRepresentationWall = ProductDefinitionWall->getRepresentations();

    Step::RefPtr<ifc2x3::IfcShapeRepresentation> ShapeRepresentationWall1 = expressDataSet->getIfcShapeRepresentation(ShapeRepresentationWall.at(0)->getKey());
    Step::RefPtr<ifc2x3::IfcShapeRepresentation> ShapeRepresentationWall2 = expressDataSet->getIfcShapeRepresentation(ShapeRepresentationWall.at(1)->getKey());
    auto RepresentationItems = ShapeRepresentationWall2->getItems();
    Step::RefPtr<ifc2x3::IfcRepresentationItem> RepresentationItem = *(RepresentationItems.begin());

    Step::RefPtr<ifc2x3::IfcExtrudedAreaSolid> ExtrudeAreaSolidWall = expressDataSet->getIfcExtrudedAreaSolid(RepresentationItem->getKey());
    auto hauteurExtrusion = ExtrudeAreaSolidWall->getDepth();

    Step::RefPtr<ifc2x3::IfcArbitraryClosedProfileDef> ArbitraryClosedProfileDefWall = expressDataSet->getIfcArbitraryClosedProfileDef(ExtrudeAreaSolidWall->getExtrudedDirection()->getKey());

    Step::RefPtr<ifc2x3::IfcPolyline> PolylineWall = expressDataSet->getIfcPolyline(ArbitraryClosedProfileDefWall->getOuterCurve()->getKey());

    for (auto point : PolylineWall->getPoints())
    {
        _points.push_back(ComputePlacementVisitor::getPoint(point.get()));
    }

    _points.pop_back();*/

    ComputePlacementVisitor placementVisitor;
    CreateConstructionPointVisitor visitor1;
    //Step::RefPtr<ifc2x3::IfcWall> wall1 = expressDataSet->getIfcWall(37);
    wallStandardCase1->acceptVisitor(&visitor1);

    std::list<Vec3> points1 = visitor1.getPoints();

    wallStandardCase1->acceptVisitor(&placementVisitor);
    Matrix4 transform1 = placementVisitor.getTransformation();

    acutPrintf(_T("vecteur 1 : (%f, %f, %f)\n"), points1.begin()->x(), points1.begin()->y(), points1.begin()->z());

    acutPrintf(_T("nb vec : %d"), points1.size());



}


extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
    switch (msg)
    {

    case AcRx::kInitAppMsg:
        acrxDynamicLinker->unlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        initApp();
        break;
    case AcRx::kUnloadAppMsg:
        unloadApp();
        break;
    default:
        break;

    }

    return AcRx::kRetOK;

}

Vec3 ComputePlacementVisitor::getPoint(ifc2x3::IfcCartesianPoint* point)
{
    Vec3 vector(0.f);

    ifc2x3::List_IfcLengthMeasure_1_3& coor =
        point->getCoordinates();
    const std::size_t size = coor.size();

    vector.x() = static_cast<float>(coor[0]);

    if (size >= 2)
    {
        vector.y() = static_cast<float>(coor[1]);

        if (size >= 3)
        {
            vector.z() = static_cast<float>(coor[2]);
        }
    }

    return vector;
}