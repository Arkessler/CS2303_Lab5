//Author:Alexi Kessler
#ifndef DESTINATION_H
#define DESTINATION_H
class Dest
{
	public:
		Dest();
		void setRow (int);
		int getRow();
		void setCol (int);
		int getCol();
		void setServ (int);
		int getServ();
	private:
		int row, col, servTime;
};

#endif
