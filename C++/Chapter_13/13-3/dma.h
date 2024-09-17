#ifndef __DMA_H__
#define __DMA_H__

class DMA {
private:
    char * class_name;

protected:
    const char *show_classname() const { return class_name; }

public:
    DMA(const char * name);
    DMA(const DMA & rs);
    virtual ~DMA();
    DMA & operator=(const DMA & rs);
    virtual void View() const = 0;
};

class baseDMA : public DMA {
private:
    char * label;
    int rating;
public:
    baseDMA(const char * ln = "null", int r = 0, const char * cn = "null");
    baseDMA(const char * ln, int r, const DMA & rs);
    baseDMA(const baseDMA & rs);
    ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    virtual void View() const;
};

class lacksDMA : public DMA {
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "null", const char * cn = "null");
    lacksDMA(const char * c, const DMA & rs);
    lacksDMA(const lacksDMA & rs);
    ~lacksDMA() {}
    lacksDMA & operator=(const lacksDMA & rs);
    virtual void View() const;
};

class hasDMA : public DMA {
private:
    char * style;
public:
    hasDMA(const char * s = "null", const char * cn = "null");
    hasDMA(const char * s, const DMA & rs);
    hasDMA(const hasDMA & rs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    virtual void View() const;
};
#endif