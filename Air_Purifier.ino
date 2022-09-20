import processing.serial.*;
import meter.*;
 
Serial port;
String[] list;
 
Meter m;
 
void setup() {
  size(950, 910);
  background(255, 255, 200);
  
   port = new Serial(this, "COM4", 9600);
 
  m = new Meter(this, 125, 25, true); 
  m.setMeterWidth(650);
  m.setFrameColor(color(100, 0, 0));
  m.setTitleFontColor(color(0, 200, 0));
  m.setPivotPointColor(color(255, 0, 0));
  m.setArcColor(color(0, 0, 200));
  m.setScaleFontColor(color(200, 100, 0));
  m.setTicMarkColor(color(217, 22, 247));
  m.setArcMinDegrees(90.0); // (start)
  m.setArcMaxDegrees(360.0); // ( end)
  m.setArcThickness(5);
  m.setNeedleThickness(4);
  // Set the meter value correspond to the scale labels.
  m.setMinScaleValue(0.0);
  m.setMaxScaleValue(800.0);
  m.setInputSignalOutOfRangeFontColor(color(0, 255, 0));
  m.setMinInputSignal(0);
  m.setMaxInputSignal(800);
 m.setHighSensorWarningActive(true);
  m.setHighSensorWarningValue((float)200.0);
  String[] scaleLabelsA = {"0", "100", "200", "300", "400", "500", "600", "700", "800"};
  m.setScaleLabels(scaleLabelsA);
 
  
  m.setTitle("Airquality (ug/m3)");
 
  // Display the digital meter value.
  m.setDisplayDigitalMeterValue(true);
}
 
void draw() {
 
  if (port.available() > 0) {
    String val = port.readString();
    list = split(val, ',');
 
float air = float(list[0]);
 
println("Airquality: " + air + " mg/m3 " );
m.updateMeter(int(air));
  }
}