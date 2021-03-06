#pragma once
#include "stdafx.h"
#include "CustomEntity.h"

namespace CustomEntity {

	FaneTriangleWrapper::FaneTriangleWrapper() : Autodesk::AutoCAD::DatabaseServices::Entity(System::IntPtr(new FaneTriangle()),true){}

	FaneTriangleWrapper::FaneTriangleWrapper(System::IntPtr unmanagedPointer,bool autoDelete) : Autodesk::AutoCAD::DatabaseServices::Entity(unmanagedPointer,autoDelete){}

	FaneTriangleWrapper::FaneTriangleWrapper(Point3d pt1, Point3d pt2, Point3d pt3) : Autodesk::AutoCAD::DatabaseServices::Entity(System::IntPtr(new FaneTriangle(GETPOINT3D(pt1), GETPOINT3D(pt2), GETPOINT3D(pt3))),true){}

	void FaneTriangleWrapper::GetVerts([Runtime::InteropServices::OutAttribute] Autodesk::AutoCAD::Geometry::Point3dCollection ^%verts) {
		verts = gcnew Point3dCollection();
		AcGePoint3dArray pt3dArray;
		GetImpObj()->getVerts(pt3dArray);
		for (size_t i = 0; i < pt3dArray.length(); i++)
		{
			verts->Add(ToPoint3d(pt3dArray[i]));
		}
	}

	double FaneTriangleWrapper::GetArea() {
		return GetImpObj()->getArea();
	}

	void FaneTriangleWrapper::SetVertAt(int index, Point3d pt) {
		GetImpObj()->setVertAt(index,GETPOINT3D(pt));
	}
}

