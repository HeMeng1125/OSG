#include <windows.h>      //�������ͷ�ļ��������gl.h�д���
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventAdapter>
#include <osgViewer/ViewerEventHandlers>
#include <osg/StateSet>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Material>
#include <osg/Image>
#include <osg/Texture2D>
#include <iostream>

osg::ref_ptr<osg::Geode> CreateBox()
{
	osg::ref_ptr<osg::Geode> geode=new osg::Geode;
	osg::ref_ptr<osg::TessellationHints> hints=new osg::TessellationHints;
	osg::ref_ptr<osg::ShapeDrawable> shape=new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.0, 0.0, 0.0), 1.0, 10.0, 10.0), hints.get());
	osg::ref_ptr<osg::Material> material=new osg::Material;
	osg::ref_ptr<osg::Texture2D> texture2D=new osg::Texture2D;
	osg::ref_ptr<osg::Image> image;

	//������ɫ
	shape->setColor(osg::Vec4(0.5, 0, 0, 0.1));
	//���þ���
	hints->setDetailRatio(0.5);
	//���ò���
	material->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4f(1.0,1.0,1.0,0.5));
	material->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4f(1.0,1.0,1.0,0.5));
	material->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4f(1.0,1.0,1.0,0.5));
	material->setShininess(osg::Material::FRONT_AND_BACK, 60.0);

	//��������
	image = osgDB::readImageFile("Images/whitemetal_diffuse.jpg");
	if (image.valid())
	{
		texture2D->setImage(image.get());
	}

	geode->getOrCreateStateSet()->setAttributeAndModes(material.get(), osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture2D.get(), osg::StateAttribute::ON);
	geode->addDrawable(shape.get());
	 
	return geode;
}

//������ͼԪ
osg::ref_ptr<osg::Node> CreateSimple()
{
	osg::ref_ptr<osg::Geode> geode=new osg::Geode;
	osg::ref_ptr<osg::Geometry> geom=new osg::Geometry;

	//����һЩ����
	osg::ref_ptr<osg::Vec3Array> coords=new osg::Vec3Array;
	//������ɫ
	osg::ref_ptr<osg::Vec4Array> colors=new osg::Vec4Array;
	geode->addDrawable(geom.get());
	//���ö���
	geom->setVertexArray(coords.get());
	//���������ʽ
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::Mode::QUADS, 0, 4));

	coords->push_back(osg::Vec3(-10.0, 0.0, -10.0));
	coords->push_back(osg::Vec3(10.0, 0.0, -10.0));
	coords->push_back(osg::Vec3(10.0, 0.0, 10.0));
	coords->push_back(osg::Vec3(-10.0, 0.0, 10.0));

	return geode;
}
int main(int argc, char* argv[])
{
	osg::ref_ptr<osgViewer::Viewer> viewer=new osgViewer::Viewer;

	viewer->setSceneData(CreateSimple());

	return viewer->run();
}