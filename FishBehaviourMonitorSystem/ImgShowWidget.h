#pragma once
#include<QtWidgets\qwidget.h>
#include<QtWidgets\qlabel.h>

#include<QtCore\qfile.h>
#include<QtCore\qtextstream.h>

#include <cv.h>     //iplimage
#include <highgui.h>//CvCapture


//  ������
//  �����������ʾһ��ͼƬQImage *src �� QLabel   *_img_label ��
//  ������Ϊ�����ؼ����ӿؼ���
//  void show_img(const QImage *src); ��ʾͼƬ
// *void set_size(const QSize size);  �ı��С
class ImgShowWidget : public QWidget
{
public:
	ImgShowWidget(QWidget *parent);
	~ImgShowWidget();
	void show_img(const QImage *src);//��ʾͼƬ
	void set_size(const QSize& size); //�ı��С

protected:
	QLabel* _img_label;
	QSize   _size;
	void setupUi();
};

//  �̳���img_show_widget
//  �����������ʾһ��ͼƬQImage *src �� QLabel   *_img_label ��
//  ������Ϊ�����ؼ����ӿؼ���
//  void show_img(const QImage *src); ��ʾͼƬ
//  void set_size(const QSize size);  �ı��С
// *void updata_img(IplImage *src);   ��ʾopencv��iplimageͼ��
class ImgShowWidget_opencv :public ImgShowWidget
{
public:
	ImgShowWidget_opencv(QWidget *parent);
	~ImgShowWidget_opencv();

	void updata_img(const IplImage *src);
private:
	IplImage *_iplImg;
	QImage   *_qimg;
};