#define readTree2018_cxx
#include "readTree2018.h"
#include <TH2.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <TGraph.h>
#include "TLorentzVector.h"
#include <vector>

void readTree2018::Loop()
{
	const bool blind_signal = false;
	gStyle->SetOptStat(kFALSE);

	if (fChain == 0) return;

	std::vector<TLorentzVector> mu1_p4_vector;
	std::vector<TLorentzVector> mu2_p4_vector;
	std::vector<TLorentzVector> mu3_p4_vector;
	std::vector<TLorentzVector> mu4_p4_vector;
	std::vector<TLorentzVector> mu12_p4_vector;
	std::vector<TLorentzVector> mu34_p4_vector;

	TH1F *mu12mass = new TH1F("mu12mass","mu12mass",60,8.5,11.5);
	mu12mass->GetXaxis()->SetTitle("#mu_{1}#mu_{2} mass (GeV)");
	TH1F *mu34mass = new TH1F("mu34mass","mu34mass",60,8,11);
	mu34mass->GetXaxis()->SetTitle("#mu_{3}#mu_{4} mass (GeV)");
	TH1F *Ypt1 = new TH1F("Ypt1","Ypt1",20,0,40);
	Ypt1->GetXaxis()->SetTitle("#Upsilon_{1} p_{T} (GeV)");
	TH1F *Ypt2 = new TH1F("Ypt2","Ypt2",20,0,40);
	Ypt2->GetXaxis()->SetTitle("#Upsilon_{2} p_{T} (GeV)");

	TH2F *Y2Dpteta = new TH2F("Y2Dpteta","Y2Dpteta",20,-5,5,20,0,40);
	Y2Dpteta->GetXaxis()->SetTitle("#Upsilon_{1} #eta");
	Y2Dpteta->GetYaxis()->SetTitle("#Upsilon_{1} p_{T} (GeV)");
	TH2F *Y2Dptphi = new TH2F("Y2Dptphi","Y2Dptphi",20,-4,4,20,0,40);
	Y2Dptphi->GetXaxis()->SetTitle("#Upsilon_{1} #phi");
	Y2Dptphi->GetYaxis()->SetTitle("#Upsilon_{1} p_{T} (GeV)");
	TH2F *Y2Detaphi = new TH2F("Y2Detaphi","Y2Detaphi",20,-5,5,20,-4,4);
	Y2Detaphi->GetXaxis()->SetTitle("#Upsilon_{1} #eta");
	Y2Detaphi->GetYaxis()->SetTitle("#Upsilon_{1} #phi");

        TH2F *SY2Dpteta = new TH2F("SY2Dpteta","SY2Dpteta",20,-5,5,20,0,40);
        SY2Dpteta->GetXaxis()->SetTitle("#Upsilon_{2} #eta");
        SY2Dpteta->GetYaxis()->SetTitle("#Upsilon_{2} p_{T} (GeV)");
        TH2F *SY2Dptphi = new TH2F("SY2Dptphi","SY2Dptphi",20,-4,4,20,0,40);
        SY2Dptphi->GetXaxis()->SetTitle("#Upsilon_{2} #phi");
        SY2Dptphi->GetYaxis()->SetTitle("#Upsilon_{2} p_{T} (GeV)");
        TH2F *SY2Detaphi = new TH2F("SY2Detaphi","SY2Detaphi",20,-5,5,20,-4,4);
        SY2Detaphi->GetXaxis()->SetTitle("#Upsilon_{1} #eta");
        SY2Detaphi->GetYaxis()->SetTitle("#Upsilon_{1} #phi");

	TH1F *h_fourMu_pt_order = new TH1F("h_fourMu_pt_order","h_fourMu_pt_order",6,0,6);
	TH1F *hfourMuMass = new TH1F("hfourMuMass","hfourMuMass",100,0,100);
	hfourMuMass->GetXaxis()->SetTitle("4 muon mass [GeV]");
	hfourMuMass->GetYaxis()->SetTitle("Candidates / GeV");
	hfourMuMass->GetYaxis()->SetLabelSize(0.03);

        TH1F *hfourMuMass_beforecut_0p05 = new TH1F("hfourMuMass_beforecut_0p05","hfourMuMass_beforecut_0p05",500,15,40);
        hfourMuMass_beforecut_0p05->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_beforecut_0p05->GetYaxis()->SetTitle("Candidates / 50 MeV");


        TH1F *hfourMuMass_beforecut_0p05_smallrange = new TH1F("hfourMuMass_beforecut_0p05_smallrange","hfourMuMass_beforecut_0p05_smallrange",160,18,26);
        hfourMuMass_beforecut_0p05_smallrange->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_beforecut_0p05_smallrange->GetYaxis()->SetTitle("Candidates / 50 MeV");

        TH1F *hfourMuMass_aftercut_0p05 = new TH1F("hfourMuMass_aftercut_0p05","hfourMuMass_aftercut_0p05",500,15,40);
        hfourMuMass_aftercut_0p05->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_aftercut_0p05->GetYaxis()->SetTitle("Candidates / 50 MeV");

        TH1F *hfourMuMass_aftercut_0p05_smallrange = new TH1F("hfourMuMass_aftercut_0p05_smallrange","hfourMuMass_aftercut_0p05_smallrange",160,18,26);
        hfourMuMass_aftercut_0p05_smallrange->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_aftercut_0p05_smallrange->GetYaxis()->SetTitle("Candidates / 50 MeV");


	TH1F *hfourMuMass_aftercut_0p1 = new TH1F("hfourMuMass_aftercut_0p1","hfourMuMass_aftercut_0p1",250,15,40);
	hfourMuMass_aftercut_0p1->GetXaxis()->SetTitle("4 muon mass [GeV]");
	hfourMuMass_aftercut_0p1->GetYaxis()->SetTitle("Candidates / 0.1 GeV");

	TH1F *hfourMuMass_aftercut_0p1_smallrange = new TH1F("hfourMuMass_aftercut_0p1_smallrange","hfourMuMass_aftercut_0p1_smallrange",80,18,26);
	hfourMuMass_aftercut_0p1_smallrange->GetXaxis()->SetTitle("4 muon mass [GeV]");
	hfourMuMass_aftercut_0p1_smallrange->GetYaxis()->SetTitle("Candidates / 0.1 GeV");

        TH1F *hfourMuMass_Diff_aftercut_0p1_smallrange = new TH1F("hfourMuMass_Diff_aftercut_0p1_smallrange","hfourMuMass_Diff_aftercut_0p1_smallrange",80,18,26);
        hfourMuMass_Diff_aftercut_0p1_smallrange->GetXaxis()->SetTitle("m(#mu_{1}#mu_{2}#mu_{3}#mu_{4}) - m(#mu_{1}#mu_{2}) - m(#mu_{3}#mu_{4}) + 2*9.46 [GeV]");
        hfourMuMass_Diff_aftercut_0p1_smallrange->GetYaxis()->SetTitle("Candidates / 0.1 GeV");
        TH1F *hfourMuMass_Diff_aftercut_0p05_smallrange = new TH1F("hfourMuMass_Diff_aftercut_0p05_smallrange","hfourMuMass_Diff_aftercut_0p05_smallrange",160,18,26);
        hfourMuMass_Diff_aftercut_0p05_smallrange->GetXaxis()->SetTitle("m(#mu_{1}#mu_{2}#mu_{3}#mu_{4}) - m(#mu_{1}#mu_{2}) - m(#mu_{3}#mu_{4}) + 2*9.46 [GeV]");
        hfourMuMass_Diff_aftercut_0p05_smallrange->GetYaxis()->SetTitle("Candidates / 50 MeV");


        TH1F *hfourMuMass_beforecut_0p1 = new TH1F("hfourMuMass_beforecut_0p1","hfourMuMass_beforecut_0p1",250,15,40);
        hfourMuMass_beforecut_0p1->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_beforecut_0p1->GetYaxis()->SetTitle("Candidates / 0.1 GeV");


        TH1F *hfourMuMass_beforecut_0p1_smallrange = new TH1F("hfourMuMass_beforecut_0p1_smallrange","hfourMuMass_beforecut_0p1_smallrange",80,18,26);
        hfourMuMass_beforecut_0p1_smallrange->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_beforecut_0p1_smallrange->GetYaxis()->SetTitle("Candidates / 0.1 GeV");


        TH1F *hfourMuMass_aftercut_0p2 = new TH1F("hfourMuMass_aftercut_0p2","hfourMuMass_aftercut_0p2",125,15,40);
        hfourMuMass_aftercut_0p2->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_aftercut_0p2->GetYaxis()->SetTitle("Candidates / 0.2 GeV");

        TH1F *hfourMuMass_aftercut_0p2_smallrange = new TH1F("hfourMuMass_aftercut_0p2_smallrange","hfourMuMass_aftercut_0p2_smallrange",40,18,26);
        hfourMuMass_aftercut_0p2_smallrange->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_aftercut_0p2_smallrange->GetYaxis()->SetTitle("Candidates / 0.2 GeV");

        TH1F *hfourMuMass_Diff_aftercut_0p2_smallrange = new TH1F("hfourMuMass_Diff_aftercut_0p2_smallrange","hfourMuMass_Diff_aftercut_0p2_smallrange",40,18,26);
        hfourMuMass_Diff_aftercut_0p2_smallrange->GetXaxis()->SetTitle("m(#mu_{1}#mu_{2}#mu_{3}#mu_{4}) - m(#mu_{1}#mu_{2}) - m(#mu_{3}#mu_{4}) + 2*9.46 [GeV]");
        hfourMuMass_Diff_aftercut_0p2_smallrange->GetYaxis()->SetTitle("Candidates / 0.2 GeV");

        TH1F *hfourMuMass_beforecut_0p2 = new TH1F("hfourMuMass_beforecut_0p2","hfourMuMass_beforecut_0p2",125,15,40);
        hfourMuMass_beforecut_0p2->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_beforecut_0p2->GetYaxis()->SetTitle("Candidates / 0.2 GeV");

        TH1F *hfourMuMass_beforecut_0p2_smallrange = new TH1F("hfourMuMass_beforecut_0p2_smallrange","hfourMuMass_beforecut_0p2_smallrange",40,18,26);
        hfourMuMass_beforecut_0p2_smallrange->GetXaxis()->SetTitle("4 muon mass [GeV]");
        hfourMuMass_beforecut_0p2_smallrange->GetYaxis()->SetTitle("Candidates / 0.2 GeV");


	TH1F *nVertices = new TH1F("nVertices","nVertices",50,0,100);
	nVertices->GetXaxis()->SetTitle("number of primary vertices per event");
	TH1F *h_number_of_Y = new TH1F("h_number_of_Y","h_number_of_Y",10,0,10);
	TH2F *Ymumu2D = new TH2F("Ymumu2D","Ymumu2D",120,-6,6,120,-6,6);
	Ymumu2D->GetXaxis()->SetTitle("#Upsilon #eta");
	Ymumu2D->GetYaxis()->SetTitle("#mu_{3}#mu_{4} #eta");
	Long64_t nentries = fChain->GetEntries();
	std::cout<<nentries<<std::endl;
	Long64_t nbytes = 0, nb = 0;

	float muonPtCut[5]={2,2.5,3,3.5,4};
	float nPassMuonPtCut[5]={0};
	float sigPassMuonPtCut[5]={0};
	float sigEffMuonPtCut[5]={0};
	float bkRejMuonPtCut[5]={0};
	float significanceMuonPtCut[5]={0};

	float vProbCut[14]={0,0.0001,0.001,0.005,0.01,0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.09,0.1};
	float nPassVProbCut[14]={0};
	float sigPassVProbCut[14]={0};
	float sigEffVProbCut[14]={0};
	float bkRejVProbCut[14]={0};
	float significanceVProbCut[14]={0};

	float nPass2d[5][14]={0};
	float sigPass2d[5][14]={0};
	float sigEff2d[5][14]={0};
	float bkRej2d[5][14]={0};
	float significance2d[5][14]={0};

	float quaCut[6]={0,1,2,3,4,5};
	float nPassQuaCut[6]={0};
	float sigPassQuaCut[6]={0};
	float sigEffQuaCut[6]={0};
	float bkRejQuaCut[6]={0};
	float significanceQuaCut[6]={0};

	float quaCut_m[6]={0,1,2,3,4,5};
	float nPassQuaCut_m[6]={0};
	float sigPassQuaCut_m[6]={0};
	float sigEffQuaCut_m[6]={0};
	float bkRejQuaCut_m[6]={0};
	float significanceQuaCut_m[6]={0};
	for (Long64_t jentry=0; jentry<nentries;jentry++) {
		Long64_t ientry = LoadTree(jentry);
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		//Make plots_mc_2016
		nVertices->Fill(numPrimaryVertices);

		//if ((trigger&2)==0) continue; //2016 trigger
		//if ((trigger&128)==0) continue;
		//if ((trigger&256)==0) continue;			//HLT_Trimuon5_3p5_2_Upsilon_Muon
		//if ((trigger&512)==0) continue;		//HLT_TrimuonOpen_5_3p5_2_Upsilon_Muon

		//std::cout << "v_mumufit_Mass->size() = " << v_mumufit_Mass->size() << std::endl;
		//std::cout << "fourMuFit_Mass->size() = " << fourMuFit_Mass->size() << std::endl;
		h_number_of_Y->Fill(v_mumufit_Mass->size());

		//orignial events in the MuOnia dataset
		int nCand = 0;
		int nCand_aftercut = 0;
		for (unsigned i=0;i<fourMuFit_Mass->size();++i) {
			TLorentzVector fourMuFit,mu1,mu2,mu3,mu4,mu12,mu34,mu1boost,mu2boost,mu3boost,mu4boost,mu12boost,mu34boost;
			fourMuFit.SetPtEtaPhiM(fourMuFit_Pt->at(i),fourMuFit_Eta->at(i),fourMuFit_Phi->at(i),fourMuFit_Mass->at(i));
			mu12.SetPtEtaPhiE(fourMuFit_mu1Pt->at(i),fourMuFit_mu1Eta->at(i),fourMuFit_mu1Phi->at(i),fourMuFit_mu1E->at(i));
			mu34.SetPtEtaPhiE(fourMuFit_mu2Pt->at(i),fourMuFit_mu2Eta->at(i),fourMuFit_mu2Phi->at(i),fourMuFit_mu2E->at(i));
			//mu3.SetPtEtaPhiE(fourMuFit_mu3Pt->at(i),fourMuFit_mu3Eta->at(i),fourMuFit_mu3Phi->at(i),fourMuFit_mu3E->at(i));
			//mu4.SetPtEtaPhiE(fourMuFit_mu4Pt->at(i),fourMuFit_mu4Eta->at(i),fourMuFit_mu4Phi->at(i),fourMuFit_mu4E->at(i));
			//mu12=mu1+mu2;
			//mu34=mu3+mu4;
			hfourMuMass->Fill(fourMuFit_Mass->at(i));
			Ymumu2D->Fill(mu12.Eta(),mu34.Eta());

			nCand++;
//			if (
					//fourMuFit_VtxProb->at(i)>0.05 &&
					//(mu3_Medium->at(i) + mu4_Medium->at(i)) >= 2
					//&& fourMuFit_mu1Pt->at(i) >= muonPtCut[0] && fourMuFit_mu2Pt->at(i) >= muonPtCut[0] && fourMuFit_mu3Pt->at(i) >= muonPtCut[0] && fourMuFit_mu4Pt->at(i) >= muonPtCut[0]
					//&& fourMuFit_Mass->at(i)>18 && fourMuFit_Mass->at(i)<26
//				) {
                                hfourMuMass_beforecut_0p05->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_beforecut_0p1->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_beforecut_0p2->Fill(fourMuFit_Mass->at(i));
                                if (fourMuFit_Mass->at(i)>18 && fourMuFit_Mass->at(i)<26)
                                {
                                hfourMuMass_beforecut_0p05_smallrange->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_beforecut_0p1_smallrange->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_beforecut_0p2_smallrange->Fill(fourMuFit_Mass->at(i));
                                }
                                if (fourMuFit_VtxProb->at(i)>0.0001)
                                {
                                hfourMuMass_aftercut_0p05->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_aftercut_0p1->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_aftercut_0p2->Fill(fourMuFit_Mass->at(i));
                                if (fourMuFit_Mass->at(i)>18 && fourMuFit_Mass->at(i)<26)
                                {
                                hfourMuMass_aftercut_0p05_smallrange->Fill(fourMuFit_Mass->at(i));
				hfourMuMass_aftercut_0p1_smallrange->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_aftercut_0p2_smallrange->Fill(fourMuFit_Mass->at(i));
                                hfourMuMass_Diff_aftercut_0p05_smallrange->Fill(fourMuFit_Mass->at(i)-mu12.M()-mu34.M()+2*9.46);
                                hfourMuMass_Diff_aftercut_0p1_smallrange->Fill(fourMuFit_Mass->at(i)-mu12.M()-mu34.M()+2*9.46);
                                hfourMuMass_Diff_aftercut_0p2_smallrange->Fill(fourMuFit_Mass->at(i)-mu12.M()-mu34.M()+2*9.46);
                                 }
                                 } // Forumu vtx cut
                                mu12mass->Fill(mu12.M());
                                mu34mass->Fill(mu34.M());
				Y2Dpteta->Fill(mu12.Eta(),mu12.Pt());
				Y2Dptphi->Fill(mu12.Phi(),mu12.Pt()); 
				Y2Detaphi->Fill(mu12.Eta(),mu12.Phi());
                                SY2Dpteta->Fill(mu34.Eta(),mu34.Pt());
                                SY2Dptphi->Fill(mu34.Phi(),mu34.Pt());
                                SY2Detaphi->Fill(mu34.Eta(),mu34.Phi()); 
                                Ypt1->Fill(mu12.Pt());
                                Ypt2->Fill(mu34.Pt());	
/*
				bool fourMu_pt_fill = false;

				if (std::min(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)) > std::max(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)))
				{h_fourMu_pt_order->Fill(0); fourMu_pt_fill = true;}		//yymm
				if (std::max(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)) > std::max(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i))
				&& std::max(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)) > std::min(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i))
				&& std::min(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)) > std::min(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)))
				{h_fourMu_pt_order->Fill(1); fourMu_pt_fill = true;}		//ymym
				if (std::max(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)) > std::max(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i))
				&& std::min(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)) > std::min(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)))
				{h_fourMu_pt_order->Fill(2); fourMu_pt_fill = true;}		//ymmy
				if (std::max(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)) > std::max(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i))
				&& std::min(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)) > std::min(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)))
				{h_fourMu_pt_order->Fill(3); fourMu_pt_fill = true;}		//myym
				if (std::max(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)) > std::max(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i))
				&& std::max(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)) > std::min(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i))
				&& std::min(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)) > std::min(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)))
				{h_fourMu_pt_order->Fill(4); fourMu_pt_fill = true;}		//mymy
				if (std::min(fourMuFit_mu3Pt->at(i), fourMuFit_mu4Pt->at(i)) > std::max(fourMuFit_mu1Pt->at(i), fourMuFit_mu2Pt->at(i)))
				{h_fourMu_pt_order->Fill(5); fourMu_pt_fill = true;}		//mmyy

				if(fourMu_pt_fill == false) std::cout << "mu1Pt = " << fourMuFit_mu1Pt->at(i)  << "mu2Pt = " << fourMuFit_mu2Pt->at(i)  << "mu3Pt = " << fourMuFit_mu3Pt->at(i)  << "mu4Pt = " << fourMuFit_mu4Pt->at(i) << std::endl;

				nCand_aftercut++;

				//fill vectors for mixing later
				mu1_p4_vector.push_back(mu1);
				mu2_p4_vector.push_back(mu2);
				mu3_p4_vector.push_back(mu3);
				mu4_p4_vector.push_back(mu4);
				mu12_p4_vector.push_back(mu12);
				mu34_p4_vector.push_back(mu34);
*/
//			}
		}

	         }

		TCanvas *c1 = new TCanvas("c1","c1");

                hfourMuMass_aftercut_0p05_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p05_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p05_smallrange.pdf");

		hfourMuMass_aftercut_0p1_smallrange->Draw("e1");
		c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p1_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p1_smallrange.pdf");

                hfourMuMass_Diff_aftercut_0p1_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_Diff_afterCut_0p1_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_Diff_afterCut_0p1_smallrange.pdf");

                hfourMuMass_Diff_aftercut_0p05_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_Diff_afterCut_0p05_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_Diff_afterCut_0p05_smallrange.pdf");

                hfourMuMass_aftercut_0p1->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p1.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p1.pdf");

                hfourMuMass_aftercut_0p05->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p05.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p05.pdf");

                hfourMuMass_beforecut_0p05_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p05_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p05_smallrange.pdf");

                hfourMuMass_beforecut_0p1_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p1_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p1_smallrange.pdf");

                hfourMuMass_beforecut_0p05->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p05.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p05.pdf");

                hfourMuMass_beforecut_0p1->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p1.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p1.pdf");

                hfourMuMass_aftercut_0p2_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p2_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p2_smallrange.pdf");

                hfourMuMass_Diff_aftercut_0p2_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_Diff_afterCut_0p2_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_Diff_afterCut_0p2_smallrange.pdf");

                hfourMuMass_aftercut_0p2->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p2.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_afterCut_0p2.pdf");

                hfourMuMass_beforecut_0p2_smallrange->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p2_smallrange.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p2_smallrange.pdf");

                hfourMuMass_beforecut_0p2->Draw("e1");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p2.png");
                c1->SaveAs("plots_mc_2016/hfourMuMass_beforeCut_0p2.pdf");

		TCanvas *c9 = new TCanvas("c9","c9");
		Ymumu2D->Draw("colz");
		c9->SaveAs("plots_mc_2016/Ymumu2D.png");
                c9->SaveAs("plots_mc_2016/Ymumu2D.pdf");
		h_number_of_Y->Draw("e1");
		c9->SetLogy();
		c9->SaveAs("plots_mc_2016/number_of_Y.png");
                c9->SaveAs("plots_mc_2016/number_of_Y.pdf");
		TCanvas *c10 = new TCanvas("c10","c10");
		Ypt1->Draw("e1");
		c10->SaveAs("plots_mc_2016/Ypt1.png");
                c10->SaveAs("plots_mc_2016/Ypt1.pdf");
		Ypt2->Draw("e1");
		c10->SaveAs("plots_mc_2016/Ypt2.png");
                c10->SaveAs("plots_mc_2016/Ypt2.pdf");
		Y2Dpteta->Draw("colz");
		c10->SaveAs("plots_mc_2016/Y2Dpteta.png");
                c10->SaveAs("plots_mc_2016/Y2Dpteta.pdf");
		Y2Dptphi->Draw("colz");
		c10->SaveAs("plots_mc_2016/Y2Dptphi.png");
                c10->SaveAs("plots_mc_2016/Y2Dptphi.pdf");
		Y2Detaphi->Draw("colz");
		c10->SaveAs("plots_mc_2016/Y2Detaphi.png");
                c10->SaveAs("plots_mc_2016/Y2Detaphi.pdf");
                SY2Dpteta->Draw("colz");
                c10->SaveAs("plots_mc_2016/SY2Dpteta.png");
                c10->SaveAs("plots_mc_2016/SY2Dpteta.pdf");
                SY2Dptphi->Draw("colz");
                c10->SaveAs("plots_mc_2016/SY2Dptphi.png");
                c10->SaveAs("plots_mc_2016/SY2Dptphi.pdf");
                SY2Detaphi->Draw("colz");
                c10->SaveAs("plots_mc_2016/SY2Detaphi.png");
                c10->SaveAs("plots_mc_2016/SY2Detaphi.pdf");
		mu12mass->Draw();
		c10->SaveAs("plots_mc_2016/Y1mass.png");
                c10->SaveAs("plots_mc_2016/Y1mass.pdf");
                mu34mass->Draw();
                c10->SaveAs("plots_mc_2016/Y2mass.png");
                c10->SaveAs("plots_mc_2016/Y2mass.pdf");
		h_fourMu_pt_order->Draw("e1");
		h_fourMu_pt_order->SetMinimum(0);
		c10->SaveAs("plots_mc_2016/FourMu_pt_order.png");
                c10->SaveAs("plots_mc_2016/FourMu_pt_order.pdf");
}
