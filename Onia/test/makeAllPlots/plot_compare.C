int plot_compare()
{
TString histo = "hfourMuMass_aftercut";
//TString histo = "hfourMuMass_physkbg_mix";
TCanvas* mycanvas = new TCanvas();
TFile *f1 = new TFile("plots_Run2018A-PromptReco/fourMuMass.root");
TH1D *h1 = (TH1D*)f1->Get(histo);
h1->Scale(1/h1->Integral());
h1->SetLineColor(kRed);
h1->SetMarkerColor(kRed);
h1->Draw();

TFile *f2 = new TFile("plots_Run2018D-PromptReco/fourMuMass.root");
TH1D *h2 = (TH1D*)f2->Get(histo);
h2->Scale(1/h2->Integral());
h2->SetLineColor(kBlue);
h2->SetMarkerColor(kBlue);
h2->Draw("same");

TLegend* leg = new TLegend(0.7,0.7,0.9,0.9);
leg->AddEntry(h1,"2018A PromptReco","lep");
leg->AddEntry(h2,"2018D PromptReco","lep");
leg->Draw("same");

mycanvas->SaveAs("Run2018A_vs_D-PromptReco_" + histo + ".png");
return 0;
}
