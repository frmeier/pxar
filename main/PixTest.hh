#ifndef PIXTEST_H
#define PIXTEST_H

#include <string>
#include <map>
#include <list>

#include <TQObject.h> 
#include <TH1.h> 
#include <TDirectory.h> 

#include "TBInterface.hh"
#include "PixSetup.hh"
#include "PixTestParameters.hh"

class PixTest: public TQObject {
public:
  PixTest(TBInterface *tb, std::string name, PixTestParameters *);
  PixTest();
  void init(TBInterface *tb, std::string name, PixTestParameters *);
  void clearHist(); 

  virtual ~PixTest();

  virtual void doTest(); 
  virtual void doAnalysis();
  
  std::string getName() {return fName; }
  std::map<std::string, std::string> getParameters() {return fParameters;} 
  bool getParameter(std::string parName, int &); 
  bool getParameter(std::string parName, float &); 
  void dumpParameters(); 
  void setTitles(TH1 *h, const char *sx, const char *sy, 
		 float size = 0.05, float xoff = 1.1, float yoff = 1.1, float lsize = 0.05, int font = 42);

  virtual bool setParameter(std::string parName, std::string sval); 


  void testDone(); // *SIGNAL*
  void update();  // *SIGNAL*
  TH1* nextHist(); 
  TH1* previousHist(); 
  

protected: 
  TBInterface          *fTB;
  PixSetup             *fPixSetup; 
  PixTestParameters    *fTestParameters; 

  std::string           fName; 

  std::map<std::string, std::string> fParameters;
  ClassDef(PixTest, 1); // testing PixTest

  TDirectory            *fDirectory; 
  std::list<TH1*>       fHistList;
  TH1*                  fDisplayedHist; 
  int NCOL, NROW; 

};

#endif