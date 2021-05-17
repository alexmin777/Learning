#ifndef PE10_GOLF_H_ 
#define PE10_GOLF_H_ 

const int Len = 40;
class golf {
private:
	char fullname[Len];
	int  handicap_;
public:
	golf(const char* name = "no one", int hc = -100);
	int setgolf();
	void handicap(int hc);
	void showgolf() const;
};
#endif // !PE10_GOLF_H_ 
