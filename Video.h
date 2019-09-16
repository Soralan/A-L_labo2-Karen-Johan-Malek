#pragma once
#pragma comment(lib, "strmiids.lib")
#pragma comment(lib, "ole32.lib")
#include <dshow.h>
class Video
{
public:
	Video();
	~Video();
	HRESULT playPause();
	HRESULT avanceRapide();
	HRESULT retourDepart();




private:
	IGraphBuilder *pGraph = NULL;
	IMediaControl *pControl = NULL;
	IMediaEvent   *pEvent = NULL;
	IMediaSeeking *pSeeking = NULL;

};

