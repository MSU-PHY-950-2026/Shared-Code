void randomVariables(){

  gStyle->SetOptStat(0);
  
  TH2D* h1 = new TH2D("h1","h1",1000,0,1,1000,-3.5,3.5);
  TH2D* h2 = new TH2D("h1","h1",1000,0,1,1000,-3,3);

  for(int i=0; i<1e5; i++){
    double x = gRandom->Rndm();
    double y = gRandom->Gaus(0,1);
    h1->Fill(x,y);
    h2->Fill(x,x*y);
  }

  h1->SetMarkerColor(2);
  h1->Draw();
}

void convolve(){

  gStyle->SetOptStat(0);
  
  TH1D* h1 = new TH1D("h1","h1",22,-0.5,10.5);
  TH1D* h2 = new TH1D("h2","h2",500,0,10);
  TH1D* h3 = new TH1D("h3","h3",100,-2,2);
  TH1D* h4 = new TH1D("h4","h4",100,-2,2);
  TH1D* h5 = new TH1D("h5","h5",100,-2,2);
    
  for(int i=0; i<1e5; i++){
    double x = gRandom->PoissonD(2);
    double y = gRandom->Gaus(x,0.5);
    h1->Fill(x);
    h2->Fill(y);
    h3->Fill(gRandom->Gaus(0,0.15));
    h4->Fill(gRandom->Gaus(0,0.35));
    h5->Fill(gRandom->Gaus(0,0.5));
  }

  TCanvas* c1 = new TCanvas();
  h1->SetLineColor(2);
  h1->SetLineWidth(2);
  h1->Draw();

  TCanvas* c2 = new TCanvas();
  h2->SetLineColor(4);
  h2->SetLineWidth(2);
  h2->Draw();

  TCanvas* c3 = new TCanvas();
  h3->SetLineColor(2);
  h4->SetLineColor(3);
  h5->SetLineColor(4);
  h3->SetLineWidth(2);
  h4->SetLineWidth(2);
  h5->SetLineWidth(2);

  h3->Draw();
  h4->Draw("same");
  h5->Draw("same");

}


void functionalVariables(){

  gStyle->SetOptStat(0);
  
  TH1D* h1 = new TH1D("h1","h1",100,-10,10);
  TH1D* h2 = new TH1D("h2","h2",100,0,100);
  TH2D* h3 = new TH2D("h3","h3",100,0,10,100,-1,1);
    
  for(int i=0; i<1e5; i++){
    double x = gRandom->Rndm()*10;
    //    double x = gRandom->Gaus(0,3);
    double y = sin(x);
    h1->Fill(x);
    h2->Fill(y);
    h3->Fill(x,y);
  }

  TCanvas* c1 = new TCanvas();
  h1->SetLineColor(2);
  h1->SetLineWidth(2);
  h1->Draw();

  TCanvas* c2 = new TCanvas();
  h2->SetLineColor(4);
  h2->SetLineWidth(2);
  h2->Draw();

  TCanvas* c3 = new TCanvas();
  h3->SetLineColor(4);
  h3->SetMarkerColor(4);
  h3->SetLineWidth(2);
  h3->Draw();

}

/*
int calculateV1(double var1, double var2){

  int returnValue = int(var1*var2);

  return returnValue;
}

int calculateV2(double var1, double var2){

  int returnValue = int(var1*var2);

  return returnValue;
}

int calculateV3(double var1, double var2){

  int returnValue = int(var1-var2);

  return returnValue;
}


// This function calculates three relationships between the two input variables.
// V1:  Multiply the two numbers, var1*var2
// V2:  Divide var1 by var2
// V3:  Subtract var2 from var1
//
// The function then returns the integer value of these operations

int calculate(int version, double var1, double var2){

  if(version<1 || version>3){
    cout << "Invalid version value: " << version << endl;
    return -1;
  }

  if(var2==0 && version==2){
    cout << "Cannot divide by zero" << endl;
    return -1;
  }
  
  // Instantiate a return variable
  int returnValue=0;

  // Check version instances
  if(version==1){
    // Multiplication
    returnValue = int(var1*var2);
  }
  else if(version==2){
    // Division
    returnValue = int(var1/var2);
  }
  else if(version==3){
    // Subtraction
    returnValue = int(var1-var2);
  }
  else{
    // version was larger or smaller than allowed range
    returnValue = -1;
  }

  // return calculated value
  return returnValue;
}


void func(){

  (people != null) && (people.get(name).getAge() >= 18) ? people2.add(people.get(name)) : people3.add(people.get(name));


}



int addNumberSequence(int number){
  return number*8;
}


int complexFunction(int var1){

  int calcOne = 0;
  int calcTwo = 0;
  int calcThree = 0;
  for(int i=0; i<var1; i++){
    calcOne += var1 + i;
    calcTwo += var1 * i;
    calcThree += calcOne - calcTwo;
  }

  return calcOne * calcTwo - calcThree;
}


int complexCalculation(int var1, int var2){

  return complexFunction(var1)+complexFunction(var2);
}



double mysteryFunction(double x1, double x2){
  return x1*x2*x2;
}


double areaOfCircle(double _PI, double _radius){

  double radiusSquared = _radius*_radius;

  double area = _PI * radiusSquared;

  return area;
}




void seriesOfOperations(){

  OutputClass output;

  manipulateOutput(output);

  cout << "Result of first calculation: " << output.data() << endl;

  manipulateAgain(output);

  cout << "Result of second calculation: " << output.data() << endl;

  manipulateOneLastTime(output);

  cout << "Result of third calculation: " << output.data() << endl;

  return;  
}
*/
