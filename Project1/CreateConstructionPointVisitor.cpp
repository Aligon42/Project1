#include "CreateConstructionPointVisitor.h"
#include "ComputePlacementVisitor.h"
#include "pch.h"

CreateConstructionPointVisitor::CreateConstructionPointVisitor() :
    ifc2x3::InheritVisitor()
{

}

bool CreateConstructionPointVisitor::visitIfcProduct(ifc2x3::IfcProduct* value)
{
    if(value->testRepresentation())
    {
        return value->getRepresentation()->acceptVisitor(this);
    }

    return true;
}

bool CreateConstructionPointVisitor::visitIfcProductRepresentation(
    ifc2x3::IfcProductRepresentation* value)
{
    for(auto representation : value->getRepresentations())
    {
        if(representation->acceptVisitor(this))
        {
            return true;
        }
    }

    return false;
}

bool CreateConstructionPointVisitor::visitIfcShapeRepresentation(
    ifc2x3::IfcShapeRepresentation* value)
{
    for(auto item : value->getItems())
    {
        if(item->acceptVisitor(this))
        {
            return true;
        }
    }

    return false;
}

bool CreateConstructionPointVisitor::visitIfcExtrudedAreaSolid(
    ifc2x3::IfcExtrudedAreaSolid* value)
{
    if(value->testSweptArea())
    {
        if(value->getSweptArea()->acceptVisitor(this))
        {
            Matrix4 transformation = ComputePlacementVisitor::getTransformation(value->getPosition());

            transformPoints(transformation);

            Vec3 ExtrusionVecteur(0., 0., 1.);

            if (value->testExtrudedDirection())
            {
                ExtrusionVecteur = ComputePlacementVisitor::getDirection(value->getExtrudedDirection());
                ExtrusionVecteur.Normalize();

                ExtrusionVecteur *= value->getDepth();
            }
            
            ExtrusionVecteur = transformation * ExtrusionVecteur;

            std::list<Vec3> tmpPoints = _points;

            for (const auto& point : tmpPoints)
            {
                _points.push_back(point + ExtrusionVecteur);
            }

            return true;
        }
    }

    return false;
}

bool CreateConstructionPointVisitor::visitIfcArbitraryClosedProfileDef(
    ifc2x3::IfcArbitraryClosedProfileDef* value)
{
    if(value->testOuterCurve())
    {
        return value->getOuterCurve()->acceptVisitor(this);
    }

    return false;
}

bool CreateConstructionPointVisitor::visitIfcPolyline(ifc2x3::IfcPolyline*
                                                      value)
{
    for(auto point : value->getPoints())
    {
        _points.push_back(ComputePlacementVisitor::getPoint(point.get()));
    }

    _points.pop_back();

    return _points.empty() == false;
}

std::list<Vec3> CreateConstructionPointVisitor::getPoints() const
{
    return _points;
}

void CreateConstructionPointVisitor::transformPoints(const Matrix4& transform)
{
    std::list<Vec3> tmpPoints = _points;

    _points.clear();

    for(const auto& point: tmpPoints)
    {
        _points.push_back(transform * point);
    }
}
