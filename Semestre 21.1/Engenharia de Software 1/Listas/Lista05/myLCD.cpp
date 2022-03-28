 #include <QLCDNumber>
 #include <QSlider>
 #include <QVBoxLayout>

 #include "myLCD.h"


 MyLCD::MyLCD(QWidget *parent)
     : QWidget(parent)
 {
     QLCDNumber *lcd = new QLCDNumber(2);
     lcd->setSegmentStyle(QLCDNumber::Filled);

     slider = new QSlider(Qt::Horizontal);
     slider->setRange(0, 99);
     slider->setValue(0);

     connect(slider, SIGNAL(valueChanged(int)),
             lcd, SLOT(display(int)));
     connect(slider, SIGNAL(valueChanged(int)),
             this, SIGNAL(valueChanged(int)));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(lcd);
     layout->addWidget(slider);
     setLayout(layout);
 }

 int MyLCD::value() const
 {
     return slider->value();
 }

 void MyLCD::setValue(int value)
 {
     slider->setValue(value);
 }
