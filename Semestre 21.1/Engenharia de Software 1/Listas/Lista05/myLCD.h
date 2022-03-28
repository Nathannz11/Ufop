 #ifndef MY_LCD_H
 #define MY_LCD_H

 #include <QWidget>

 class QSlider;

 class MyLCD : public QWidget
 {
     Q_OBJECT

 public:
     MyLCD(QWidget *parent = 0);

     int value() const;

 public slots:
     void setValue(int value);

 signals:
     void valueChanged(int newValue);

 private:
     QSlider *slider;
 };

 #endif
