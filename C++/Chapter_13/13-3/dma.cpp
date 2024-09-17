#include <iostream>
#include "dma.h"

DMA::DMA(const char * name)
{
    class_name = new char[strlen(name) + 1];
    strcpy(class_name, name);
}

DMA::DMA(const DMA & rs)
{
    class_name = new char[strlen(rs.class_name) + 1];
    strcpy(class_name, rs.class_name);
}

DMA::~DMA()
{
    delete[] class_name;
}

DMA & DMA::operator=(const DMA & rs)
{
    if (this == &rs)
        return *this;
    
    delete[] class_name;
    class_name = new char[strlen(rs.class_name) + 1];
    strcpy(class_name, rs.class_name);

    return *this;
}



baseDMA::baseDMA(const char * ln, int r, const char * cn) : DMA(cn)
{
    label = new char[strlen(ln) + 1];
    strcpy(label, ln);
    rating = r; 
}

baseDMA::baseDMA(const char * ln, int r, const DMA & rs) : DMA(rs)
{
    label = new char[strlen(ln) + 1];
    strcpy(label, ln);
    rating = r; 
}

baseDMA::baseDMA(const baseDMA & rs) : DMA(rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating; 
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;

    DMA::operator=(rs);

    delete [] label;
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;

    return *this;
}

void baseDMA::View() const
{
    std::cout << "Classname: " << show_classname() << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}



lacksDMA::lacksDMA(const char * c, const char * cn) : DMA(cn)
{
    int len = strlen(c);
    if (len > COL_LEN)
        len = COL_LEN;
    
    strncpy(color, c, len);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const DMA & rs) : DMA(rs)
{
    int len = strlen(c);
    if (len > COL_LEN)
        len = COL_LEN;
    
    strncpy(color, c, len);
    color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const lacksDMA & rs) : DMA(rs)
{
    int len = strlen(rs.color);
    if (len > COL_LEN)
        len = COL_LEN;
    
    strncpy(color, rs.color, len);
    color[COL_LEN - 1] = '\0';
}

lacksDMA & lacksDMA::operator=(const lacksDMA & rs)
{
    if (this == &rs)
        return *this;
    
    DMA::operator=(rs);
    memcpy(color, rs.color, COL_LEN);

    return *this;
}

void lacksDMA::View() const
{
    std::cout << "Classname: " << show_classname() << std::endl;
    std::cout << "Color: " << color << std::endl;
}



hasDMA::hasDMA(const char * s, const char * cn) : DMA(cn)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMA & rs) : DMA(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & rs) : DMA(rs)
{
    style = new char[strlen(rs.style) + 1];
    strcpy(style, rs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
    if (this != &rs)
        return *this;
    
    delete [] style;
    DMA::operator=(rs);
    style = new char[strlen(rs.style) + 1];
    strcpy(style, rs.style); 

    return *this;
}

void hasDMA::View() const
{
    std::cout << "Classname: " << show_classname() << std::endl;
    std::cout << "Style: " << style << std::endl;
}