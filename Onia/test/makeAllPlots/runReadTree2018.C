#include "readTree2018.C"
void runReadTree2018()
{
   TChain *chain = new TChain("rootuple/oniaTree","");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/FourMuon_Run2018v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av1-MuMuGammaRootuple-2018A_Rereco.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Bv1-MuMuGammaRootuple-2018B_Rereco.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av1-MuMuGammaRootuple-v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av2-MuMuGammaRootuple-2018A_v2_no_overlap.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Av3-MuMuGammaRootuple-v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Bv1-MuMuGammaRootuple-v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Bv2-MuMuGammaRootuple-v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Cv1-MuMuGammaRootuple-v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Cv2-MuMuGammaRootuple-v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Cv3-MuMuGammaRootuple-v5.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/huiwang/MuOnia/Run2018Dv2-MuMuGammaRootuple-v5.root");
	//chain->Add("../Rootuple_filter1ZeroBiasMuons_3plus1.root");
	//chain->Add("../Rootuple_filter2ZeroBiasMuons_2plus2.root");
	//chain->Add("/eos/uscms/store/user/zhenhu/MuOnia/Run2017_v34.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/FourMuon_Run2018Av5.root");
   readTree2018 a(chain);
   a.Loop();
}
