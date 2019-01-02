#include "readTree2018.C"
void runReadTree2018()
{
   TChain *chain = new TChain("rootuple/oniaTree","");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/FourMuon_Run2018v5.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/FourMuon_Run2017v7.root");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/FourMuon_Run2016v2.root");
	//chain->Add("../Rootuple_filter1ZeroBiasMuons_3plus1.root");
	//chain->Add("../Rootuple_filter2ZeroBiasMuons_2plus2.root");
	//chain->Add("/eos/uscms/store/user/zhenhu/MuOnia/Run2017_v34.root");
	//chain->Add("root://cmsxrootd.fnal.gov//store/user/zhenhu/MuOnia/Rootuple_2016_chib_noMassConstrain_v12.root");
   readTree2018 a(chain);
   a.Loop();
}
