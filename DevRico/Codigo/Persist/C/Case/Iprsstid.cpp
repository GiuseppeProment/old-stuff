//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: IPersistID; Pseudo Package body
//## Subsystem: <Top Level>
//## Source file: c:\docume~1\projetos\persist\codigo\casecode\iprsstid.cpp


//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// IPersistID
#include "IPrsstID.h"

//## begin module.additionalDeclarations preserve=yes
#pragma package(smart_init)
//## end module.additionalDeclarations


// Class IPersistID 


//## begin IPersistID::sequencial.attr preserve=no  private: static int {V} 0
int IPersistID::m_sequencial = 0;
//## end IPersistID::sequencial.attr

//## begin IPersistID::CRAE.attr preserve=no  public: static int {V} 0
int IPersistID::m_CRAE = 0;
//## end IPersistID::CRAE.attr

//## begin IPersistID::RAP.attr preserve=no  public: static int {V} 0
int IPersistID::m_RAP = 0;
//## end IPersistID::RAP.attr

IPersistID::IPersistID()
  //## begin IPersistID::IPersistID%.hasinit preserve=no
  //## end IPersistID::IPersistID%.hasinit
  //## begin IPersistID::IPersistID%.initialization preserve=yes
  //## end IPersistID::IPersistID%.initialization
{
  //## begin IPersistID::IPersistID%.body preserve=yes
  //## end IPersistID::IPersistID%.body
}

IPersistID::IPersistID(const IPersistID &right)
  //## begin IPersistID::IPersistID%copy.hasinit preserve=no
  //## end IPersistID::IPersistID%copy.hasinit
  //## begin IPersistID::IPersistID%copy.initialization preserve=yes
  //## end IPersistID::IPersistID%copy.initialization
{
  //## begin IPersistID::IPersistID%copy.body preserve=yes
  m_id = right.m_id;
  //## end IPersistID::IPersistID%copy.body
}


IPersistID::~IPersistID()
{
  //## begin IPersistID::~IPersistID%.body preserve=yes
  //## end IPersistID::~IPersistID%.body
}


const IPersistID & IPersistID::operator=(const IPersistID &right)
{
  //## begin IPersistID::operator=%.body preserve=yes
  m_id = right.m_id;
  return *this;
  //## end IPersistID::operator=%.body
}



//## Other Operations (implementation)
IPersistID& IPersistID::generate()
{
  //## begin IPersistID::generate%909013228.body preserve=yes
  #ifdef CBUILDER
  struct timeb timebuffer;
  #else
  struct _timeb timebuffer;
  #endif
  struct tm *newtime;

  #ifdef CBUILDER
	ftime( &timebuffer );             // para pegar os milisegundos
  #else
	_ftime( &timebuffer );             // para pegar os milisegundos
  #endif

  newtime = localtime( & timebuffer.time ); /* Convert to local time. */

  union {
  struct
  {
    char data[11];
    char diaAno[9];
    char sec[27];
    char RAP[8];
    char CRAE[9];
  } Original ;
  char Bytes[8][8];
  char MeioBytes[16][4];
  char Tudo[65];
  } aUniao;

  aUniao.Tudo[64] = 0;
  DecToBin(newtime->tm_year+1900,aUniao.Original.data,11);
  DecToBin(newtime->tm_yday,aUniao.Original.diaAno,9);
  DecToBin(
    ((newtime->tm_sec+(newtime->tm_min*60)+(newtime->tm_hour*3600))*1000)+
    timebuffer.millitm
    ,aUniao.Original.sec,27);
  DecToBin(RAP(),aUniao.Original.RAP,8);
  DecToBin(CRAE(),aUniao.Original.CRAE,9);

	/*
  char key[9];
  key[8]= 0;
  int i;
  for (i=0;i<8;i++)
    key[i] = BinToByte(aUniao.Bytes[i],8);
	*/

	char hexChars[17]="0123456789ABCDEF";
	char hexKey[17];
	hexKey[16]=0;
	// converter cada byte do key para hexadecimal
	int i;
  for (i=0;i<16;i++) 
    hexKey[i] = hexChars[ BinToByte(aUniao.MeioBytes[i],4) ];

  m_id = "'";
  m_id += IString(hexKey)+"'";
  //## end IPersistID::generate%909013228.body

  return *this;
}

char* IPersistID::asString()
{
  //## begin IPersistID::asString%908596369.body preserve=yes
  //## end IPersistID::asString%908596369.body

  return m_id;
}

IPersistID& IPersistID::setValue(char* valor)
{
  //## begin IPersistID::setValue%909013229.body preserve=yes
  m_id = "'";
	m_id += valor;
	m_id += "'";
  //## end IPersistID::setValue%909013229.body

  return *this;
}

int IPersistID::RAP()
{
  //## begin IPersistID::RAP%924574177.body preserve=yes
	if (m_RAP++>255) m_RAP=0;
	return m_RAP;
  //## end IPersistID::RAP%924574177.body
}

//## Get and Set Operations for Class Attributes (implementation)

int IPersistID::sequencial()
{
  //## begin IPersistID::sequencial%.get preserve=no
  return m_sequencial;
  //## end IPersistID::sequencial%.get
}

void IPersistID::setsequencial(const int value)
{
  //## begin IPersistID::setsequencial%.set preserve=no
  m_sequencial = value;
  //## end IPersistID::setsequencial%.set
}

int IPersistID::CRAE()
{
  //## begin IPersistID::CRAE%.get preserve=no
  return m_CRAE;
  //## end IPersistID::CRAE%.get
}

void IPersistID::setCRAE(const int value)
{
  //## begin IPersistID::setCRAE%.set preserve=no
  m_CRAE = value;
  //## end IPersistID::setCRAE%.set
}

void IPersistID::setRAP(const int value)
{
  //## begin IPersistID::setRAP%.set preserve=no
  m_RAP = value;
  //## end IPersistID::setRAP%.set
}


// Additional Declarations
//## begin IPersistID.declarations preserve=yes

//## end IPersistID.declarations




