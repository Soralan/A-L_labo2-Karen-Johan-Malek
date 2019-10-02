#pragma once
#include <iostream>
#include <string>
#pragma comment(lib, "strmiids.lib")
#pragma comment(lib, "ole32.lib")
#include <dshow.h>

class Video
{
public:
	Video();
	~Video();
	HRESULT jouerArreter();
	HRESULT avanceRapide();
	HRESULT retourDepart();
	HRESULT Arret();
	HRESULT getEtat() { return mEtat; };

	HRESULT ouvrir(std::string nomFichier);
	std::wstring s2ws(const std::string& s);

private:
	IGraphBuilder *pGraph;
	IMediaControl *pControl;
	IMediaEvent   *pEvent;
	IMediaSeeking *pSeeking;
	HRESULT mEtat;
	bool result;
	bool actif;
	bool vitesse;
};