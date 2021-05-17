#include "dma.h"
#include <iostream>
#include <cstring>

DMA::DMA(const char * l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

DMA::DMA(const DMA & rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

DMA::~DMA()
{
	delete[] label;
}

DMA & DMA::operator=(const DMA & rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

void DMA::View() const
{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

std::ostream & operator<<(std::ostream & os, const DMA & rs)
{
	rs.View();
	return os;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r)
	: DMA(l, r)
{
	strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const DMA & rs)
	: DMA(rs)
{
	strncpy(color, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA & ls)
	:DMA(ls)
{
	strcpy(color, ls.color);
}

void lacksDMA::View() const
{
	DMA::View();
	std::cout << "Color: " << color << std::endl;
}

hasDMA::hasDMA(const char * s, const char * l, int r)
	:DMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMA & rs)
	:DMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
	:DMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA& rs)
{
	if (this == &rs)
		return *this;

	delete[] style;
	DMA::operator=(rs);
	style = new char[strlen(rs.style) + 1];
	strcpy(style, rs.style);

	return *this;
}

void hasDMA::View() const
{
	DMA::View();
	std::cout << "Style: " << style << std::endl;
}