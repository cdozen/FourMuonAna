#include "readTree2018.C"
void runReadTree2018()
{
   TChain *chain = new TChain("rootuple/oniaTree","");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av1-MuMuGammaRootuple-2018A_Rereco.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Bv1-MuMuGammaRootuple-2018B_Rereco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av1-MuMuGammaRootuple-2018Av1_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av2-MuMuGammaRootuple-2018Av2_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av3-MuMuGammaRootuple-2018Av3_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Bv1-MuMuGammaRootuple-2018B_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Bv2-MuMuGammaRootuple-2018B_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Cv1-MuMuGammaRootuple-2018C_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Cv2-MuMuGammaRootuple-2018C_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Cv3-MuMuGammaRootuple-2018C_promptReco.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Dv2-MuMuGammaRootuple-2018D_promptReco.root");

	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2017Bv1-MuMuGammaRootuple-2017_Rereco.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2017Cv1-MuMuGammaRootuple-2017_Rereco.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2017Dv1-MuMuGammaRootuple-2017_Rereco.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2017Ev1-MuMuGammaRootuple-2017_Rereco.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2017Fv1-MuMuGammaRootuple-2017_Rereco.root");

	//chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/FourMuon_Run2018v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/FourMuon_Run2018Av5.root");
   readTree2018 a(chain);
   a.Loop();
}
