#include "Video.h"



Video::Video()
{
	pGraph = NULL;
	pControl = NULL;
	pEvent = NULL;
	pSeeking = NULL;
	actif = 1;
	vitesse = 0;
	mEtat = CoInitialize(NULL);
	if (FAILED(mEtat))
	{
		printf("ERROR - Could not initialize COM library");
		return;
	}

	mEtat = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder, (void **)&pGraph);
	if (FAILED(mEtat))
	{
		printf("ERROR - Could not create the Filter Graph Manager.");
		return;
	}

	mEtat = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
	mEtat = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);
	mEtat = pGraph->QueryInterface(IID_IMediaSeeking, (void **)&pSeeking);


}


Video::~Video()
{
}

HRESULT Video::playPause()
{

	if(SUCCEEDED(mEtat))
	{
		if(actif)
		{
			mEtat = pControl->Run();
			actif = 0;
		
		}
		else
		{
		
		mEtat = pControl->Pause();
		actif = 1;
		}
	
	}
	
	return mEtat;
}



HRESULT Video::avanceRapide()
{
	if (vitesse)
	{
		mEtat= pSeeking->SetRate(1.0);
		vitesse = 0;
	}
	else {
		mEtat = pSeeking->SetRate(4.0);
		vitesse = 1;
	}
	return mEtat;
}

HRESULT Video::retourDepart()
{

	if (SUCCEEDED(mEtat))
	{

		REFERENCE_TIME rtNow = 0,
			
			mEtat = pSeeking->SetPositions(
				&rtNow, AM_SEEKING_AbsolutePositioning,
				NULL, AM_SEEKING_NoPositioning
			);
	}
	return mEtat;
}

HRESULT Video::Arret()
{
	mEtat = pControl->Stop();
	return mEtat;
}




HRESULT Video::open(std::string nomVideo)
{
	std::wstring stemp = s2ws(nomVideo);
	LPCWSTR result = stemp.c_str();
	//std::cout << getEtat();
	mEtat = pGraph->RenderFile(stemp.c_str(), NULL);
	return mEtat;
}

std::wstring Video::s2ws(const std::string & s)
{

	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
