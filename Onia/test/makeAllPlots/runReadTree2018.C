#include "readTree2018.C"
void runReadTree2018()
{
   TChain *chain = new TChain("rootuple/oniaTree","");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");
	chain->Add("root://cmsxrootd.fnal.gov//store/user/");

   readTree2018 a(chain);
   a.Loop();
}
