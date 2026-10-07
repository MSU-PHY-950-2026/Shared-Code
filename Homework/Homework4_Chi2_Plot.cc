void h1_style(TH1D* h1, const char* title){
  
  h1->GetXaxis()->SetTitle("X");
  h1->GetYaxis()->SetTitle("N(X)");
  h1->GetXaxis()->SetTitleSize(0.05);
  h1->GetYaxis()->SetTitleSize(0.05);

  h1->GetXaxis()->SetLabelSize(0.04);
  h1->GetYaxis()->SetLabelSize(0.04);
  h1->SetTitle(title);

  h1->SetMaximum(1.25*h1->GetMaximum());

}

void Homework4_Chi2_Plot(){
  // Tell ROOT to not plot the statistics box on the histograms
  gStyle->SetOptStat(0);

  // Open the file with the histograms
  TFile* fin = new TFile("hw4_chi2.root","READ");

  // Extract histograms
  TH1D* h1 = (TH1D*)fin->Get("Hypothesis 1");
  TH1D* h2 = (TH1D*)fin->Get("Hypothesis 2");
  TH1D* data = (TH1D*)fin->Get("Data");

  // Set the data style with error bars
  data->SetLineColor(1);
  data->SetMarkerStyle(22);
  data->SetMarkerSize(1);

  // Adjust the style of the first histogram to be plotted
  h1_style(h1,"");

  // Reduce the number of bins from 100 to 25
  int rebinFactor = 4;
  data->Rebin(rebinFactor);
  h1->Rebin(rebinFactor);
  h2->Rebin(rebinFactor);

  // Normalize hypotheses to the data integral
  h1->Scale(data->Integral());
  h2->Scale(data->Integral());
  
  // Report integrals
  cout << "Integral H1: " << h1->Integral() << ", Integral H2: " << h2->Integral() << endl;

  //print out contents of each bin of each histogram
  if(true){
    cout << "Histogram Bin Contents:" << endl;
    cout << "Format: <bin number> <h1 bin content> <h2 bin content> <data bin content>" << endl;
    for(int i=1; i<=h1->GetNbinsX(); i++){
      cout << "Bin " << i << ": " << h1->GetBinContent(i) <<  "," << h2->GetBinContent(i) << "," << data->GetBinContent(i) << endl;
    }
  }
  

  // Now make a plot
  TLegend* leg = new TLegend(0.65,0.6, 0.95, 0.85);
  leg->AddEntry(h1, "Hypothesis 1");
  leg->AddEntry(h2, "Hypothesis 2");
  leg->AddEntry(data, "Data");
  leg->SetFillColor(0);

  TCanvas* c1 = new TCanvas("c1","c1");
  h1->Draw();
  h2->Draw("same");
  data->Draw("PEsame");
  c1->SetLeftMargin(0.11);
  c1->SetBottomMargin(0.11);
  c1->SetTopMargin(0.035);
  c1->SetRightMargin(0.035);
  leg->Draw("same");
  c1->Print("myPlot.jpg");
}

