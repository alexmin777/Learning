#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA{
private:
	char * label;
	int rating;

public:
	DMA(const char * l = "null", int r = 0);
	DMA(const DMA & rs);
	virtual ~DMA() = 0;
	DMA & operator=(const DMA & rs);
	virtual void View() const;
	friend std::ostream & operator<<(std::ostream & os, const DMA & rs);
};

class baseDMA : public DMA{
public:
	baseDMA(const char * l = "null", int r = 0) : DMA(l, r) {}
};

class lacksDMA : public DMA{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];

public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const DMA & rs);
	lacksDMA(const lacksDMA & ls);
	virtual void View() const;
};

class hasDMA : public DMA{
private:
	char * style;

public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const DMA & rs);
	hasDMA(const hasDMA & hs);
	virtual ~hasDMA();
	hasDMA & operator=(const hasDMA& rs);
	virtual void View() const;
};
#endif