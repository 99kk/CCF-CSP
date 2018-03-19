#include <iostream>
#include <string>
using namespace std;

bool check(int cur, string condition)
{
	if(condition.compare("*") == 0)
		return true;
	int i;
	int start = 0, end = 0;
	for(i = 0; i < condition.size();i++ )
	{
		start = 0; end = 0;
		if(isdigit(condition[i]))
			while(condition[i]!= ',' && condition[i]!= '-' && i < condition.size())
			{
				start = start * 10 + condition[i]-'0';
				i++;
			}
		else
		{
			switch (condition[i]){
				case 'J':
					{
						if(condition[i+1]=='a') start = 1;			//Jan
						else if(condition[i+2] == 'n') start = 6;	//Jun
						else if(condition[i+2] == 'l') start = 7;	//Jul
					} break;
				case 'F':
					{
						if(condition[i+1] == 'e') start = 2; //Feb
						else start = 5;	//Fri
					} break;
				case 'M':
					{
						switch (condition[i+2])
							case 'r': start = 3; break; //Mar
							case 'y': start = 5; break; //May
							case 'n': start = 1; break; //Mon
					} break;
				case 'A':
					{
						if(condition[i+1] == 'p') start = 4; //Apr
						else start = 8; //Aug
					} break;
				case 'S':
					{
						if(condition[i+1] == 'e') start = 9; //Sep
						else if(condition[i+1] == 'u') start = 0; //Sun
						else start = 6; //Sat
					} break;
				case 'O': start = 10;break; //Oct
				case 'N': start = 11; break; //Nov
				case 'D': start = 12; break; //Dec
				case 'T':
					{
						if(condition[i+1] == 'u') start = 2; //Tue
						else start = 4; //Thu
					} break;
				case 'W': start = 3; break; //Wed
			}
			i = i + 3;
		}
		
		if( i < condition.size() && condition[i] == '-')
		{
			i++;
			if(condition[i] >= '0' && condition[i]<= '9')
				while(condition[i]!= ',' && i < condition.size())
				{
					end = end * 10 + condition[i] - '0';
					i++;
				}
			else
			{
				switch (condition[i]){
					case 'J':
						{
							if(condition[i+1]=='a') end = 1;			//Jan
							else if(condition[i+2] == 'n') end = 6;	//Jun
							else if(condition[i+2] == 'l') end = 7;	//Jul
						} break;
					case 'F':
						{
							if(condition[i+1] == 'e') end = 2; //Feb
							else end = 5;	//Fri
						} break;
					case 'M':
						{
							switch (condition[i+2])
								case 'r': end = 3; break; //Mar
								case 'y': end = 5; break; //May
								case 'n': end = 1; break; //Mon
						} break;
					case 'A':
						{
							if(condition[i+1] == 'p') end = 4; //Apr
							else end = 8; //Aug
						} break;
					case 'S':
						{
							if(condition[i+1] == 'e') end = 9; //Sep
							else if(condition[i+1] == 'u') end = 0; //Sun
							else end = 6; //Sat
						} break;
					case 'O': end = 10;break; //Oct
					case 'N': end = 11; break; //Nov
					case 'D': end = 12; break; //Dec
					case 'T':
						{
							if(condition[i+1] == 'u') end = 2; //Tue
							else end = 4; //Thu
						} break;
					case 'W': end = 3; break; //Wed
				}
				i = i + 3;
			}
		}
		else 
			end = start;
			
		if (cur >= start && cur <= end)
			return true;
	}
	return false;
}

void print(int curYear, int curMonth, int curDay, int curHour, int curMin, string command)
{
	cout<<curYear;
	if(curMonth < 10) cout<<0;
	cout<<curMonth;
	if(curDay < 10) cout<<0;
	cout<<curDay;
	if(curHour < 10) cout<<0;
	cout<<curHour;
	if(curMin < 10) cout<<0;
	cout<<curMin;
	cout<<" "<<command<<endl;
}


 


int main(int argc, char** argv) {
	int n;
	string s ,t;
	cin>>n>>s>>t;
	int i,j;
	string minutes[20], hours[20], dayOfMonth[20], month[20], dayOfWeek[20], command[20];
	for(i = 0; i < n; i++)
	{
		cin>>minutes[i]>>hours[i]>>dayOfMonth[i]>>month[i]>>dayOfWeek[i]>>command[i];	
	}
	
	int startY, startM, startD, startH, startMin,  endY, endM, endD, endH, endMin;
	startY	= (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
	startM	= (s[4]-'0')*10 + (s[5]-'0');
	startD	= (s[6]-'0')*10 + (s[7]-'0');
	startH	= (s[8]-'0')*10 + (s[9]-'0');
	startMin= (s[10]-'0')*10 + (s[11]-'0');
	endY	= (t[0]-'0')*1000 + (t[1]-'0')*100 + (t[2]-'0')*10 + (t[3]-'0');
	endM 	= (t[4]-'0')*10 + (t[5]-'0');
	endD 	= (t[6]-'0')*10 + (t[7]-'0');
	endH 	= (t[8]-'0')*10 + (t[9]-'0');
	endMin 	= (t[10]-'0')*10 + (t[11]-'0');
	
	int days = 0;
	int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(i = 1970; i < startY; i++)
		days += (365+ ((i%4==0 && i%100!=0)||i%400==0) ); 
	for(i = 1; i < startM; i++)
	{
		if(i == 2 && ((startY%4==0 && startY%100!=0) || startY%400==0))
			days+= 29;
		else
			days+= monthDays[i];
	}
	days += (startD-1);
	
	int curWeekDay = 4;
	curWeekDay = (days + curWeekDay) % 7;
	
	int curYear, curMonth, curDay, curHour, curMin;
	bool minCheck[20], hourCheck[20], dayCheck[20], monthCheck[20],  weekCheck[20];
	
	for(i = 0; i <n; i++)
	{
		hourCheck[i] = check(startH, hours[i]);
		dayCheck[i] = check(startD, dayOfMonth[i]);
		monthCheck[i] = check(startM, month[i]);
		weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
	}
	
	if(startY == endY)
	{
		if((startY%4==0 && startY%100!=0) || startY%400==0)
			monthDays[2] =  29;
		else
			monthDays[2] = 28;
			
		if(startM == endM)
		{
			if(startD == endD)
			{
				if(startH == endH)
				{
					if(startMin == endMin)
					{
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(startMin, minutes[i]))
								print(startY,startM, startD,startH, startMin, command[i]);
						return 0;
					}
					else
					{	
						for(curMin = startMin; curMin < endMin; curMin++)
							for(i = 0; i < n; i++)
								if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
									print(startY,startM, startD,startH, curMin, command[i]);
						return 0;
					}

				}
				else
				{
					for(curMin = startMin; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
								print(startY, startM, startD, startH, curMin, command[i]);
					for(curHour = startH+1; curHour < endH; curHour++)
						for(curMin = 0; curMin <= 59; curMin++)
							for(i = 0; i < n; i++)
								if(monthCheck[i] && dayCheck[i] && weekCheck[i] &&check(curHour, hours[i])&& check(curMin, minutes[i]))
									print(startY, startM, startD, curHour, curMin, command[i]);
					for(curMin = 0; curMin < endMin; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && check(endH, hours[i]) && check(curMin, minutes[i]))
								print(startY, startM, startD, endH, curMin, command[i]);
					return 0;
				}
			}
			else
			{
				for(curMin = startMin; curMin <= 59; curMin++)
					for(i = 0; i < n; i++)
						if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
							print(startY,startM, startD,startH,curMin, command[i]);

				for(curHour = startH+1; curHour <= 23; curHour++)
					for(curMin = 0; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && check(curHour, hours[i]) && check(curMin, minutes[i]))
								print(startY, startM, startD, curHour, curMin, command[i]);	
								
				for(curDay = startD+1; curDay < endD; curDay++)
				{
					curWeekDay = (curWeekDay + 1) % 7;
					for(i = 0; i <n; i++)
					{
						dayCheck[i] = check(curDay, dayOfMonth[i]);
						weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
					}
					for(curHour = 0; curHour <= 23; curHour++)
					{
						for(i = 0; i < n; i++)
							hourCheck[i] = check(curHour, hours[i]);
							
						for(curMin = 0; curMin <= 59; curMin++)
							for(i = 0; i < n; i++)
								if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
									print(startY, startM, curDay, curHour, curMin, command[i]);
					}
				}
				curWeekDay = (curWeekDay + 1) % 7;
				for(i = 0; i <n; i++)
				{
					dayCheck[i] = check(endD, dayOfMonth[i]);
					weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
				}
				for(curHour = 0; curHour < endH; curHour++)
				{
					for(i = 0; i < n; i++)
						hourCheck[i] = check(curHour, hours[i]);
					for(curMin = 0; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
								print(endY, endM, endD, curHour, curMin, command[i]);	
				}
				for(i = 0; i < n; i++)
						hourCheck[i] = check(endH, hours[i]);
				for(curMin = 0; curMin < endMin; curMin++)
					for(i = 0; i < n; i++)
						if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
							print(endY, endM, endD, endH, curMin, command[i]);
				return 0;
			}
		}
		else
		{
			for(curMin = startMin; curMin <= 59; curMin++)
					for(i = 0; i < n; i++)
						if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
							print(startY,startM, startD,startH,curMin, command[i]);

				for(curHour = startH+1; curHour <= 23; curHour++)
					for(curMin = 0; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && check(curHour, hours[i]) && check(curMin, minutes[i]))
								print(startY, startM, startD, curHour, curMin, command[i]);	
								
				for(curDay = startD+1; curDay <= monthDays[startM]; curDay++)
				{
					curWeekDay = (curWeekDay + 1) % 7;
					for(i = 0; i < n; i++)
					{
						dayCheck[i] = check(curDay, dayOfMonth[i]);
						weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
					}
					for(curHour = 0; curHour <= 23; curHour++)
					{
						for(i = 0; i < n; i++)
							hourCheck[i] = check(curHour, hours[i]);
							
						for(curMin = 0; curMin <= 59; curMin++)
							for(i = 0; i < n; i++)
								if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
									print(startY, startM, curDay, curHour, curMin, command[i]);
					}
				}
				
				for(curMonth = startM+1; curMonth < endM; curMonth++)
				{
						for(i = 0; i < n; i++)
						{
							monthCheck[i] = check(curMonth, month[i]);
						}
						for(curDay = 1; curDay <= monthDays[curMonth]; curDay++)
						{
							curWeekDay = (curWeekDay + 1) % 7;
							for(i = 0; i <n; i++)
							{
								dayCheck[i] = check(curDay, dayOfMonth[i]);
								weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
							}
							for(curHour = 0; curHour <= 23; curHour++)
							{
								for(i = 0; i <n; i++)
									hourCheck[i] = check(curHour, hours[i]);
								for(curMin = 0; curMin <= 59; curMin++)
									for(i = 0; i < n; i++)
										if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
											print(startY, curMonth, curDay, curHour, curMin, command[i]);
							}
						}
				}
				
				for(i = 0; i < n; i++)
					monthCheck[i] = check(endM, month[i]);
				for(curDay = 1; curDay < endD; curDay++)
				{
					curWeekDay = (curWeekDay + 1) % 7;
					for(i = 0; i <n; i++)
					{
						dayCheck[i] = check(curDay, dayOfMonth[i]);
						weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
					}
					for(curHour = 0; curHour <= 23; curHour++)
					{
						for(i = 0; i < n; i++)
							hourCheck[i] = check(curHour, hours[i]);
							
						for(curMin = 0; curMin <= 59; curMin++)
							for(i = 0; i < n; i++)
								if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
									print(endY, endM, curDay, curHour, curMin, command[i]);
					}
				}
				
				curWeekDay = (curWeekDay + 1) % 7;
				for(i = 0; i < n; i++)
				{
					dayCheck[i] = check(endD, dayOfMonth[i]);
					weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
				}
				for(curHour = 0; curHour < endH; curHour++)
				{
					for(i = 0; i < n; i++)
						hourCheck[i] = check(curHour, hours[i]);
					for(curMin = 0; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
								print(endY, endM, endD, curHour, curMin, command[i]);	
				}
				for(i = 0; i < n; i++)
					hourCheck[i] = check(endH, hours[i]);
				for(curMin = 0; curMin < endMin; curMin++)
					for(i = 0; i < n; i++)
						if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
							print(endY, endM, endD, endH, curMin, command[i]);
		}
		
		
		return 0;
	}
	
	
	for(curMin = startMin; curMin <= 59; curMin++)
		for(i = 0; i < n; i++)
			if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
				print(startY,startM, startD,startH,curMin, command[i]);

	
	for(curHour = startH+1; curHour <= 23; curHour++)
	{
		for(i = 0; i < n; i++)
			hourCheck[i] = check(curHour, hours[i]);
			
		for(curMin = 0; curMin <= 59; curMin++)
			for(i = 0; i < n; i++)
				if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
					print(startY, startM, startD, curHour, curMin, command[i]);	
	}
	
	if((startY%4==0 && startY%100!=0) || startY%400==0)
		monthDays[2] = 29 ;
	else
		monthDays[2] = 28;
	
	for(curDay = startD+1; curDay <= monthDays[startM]; curDay++)
	{
		curWeekDay = (curWeekDay + 1) % 7;
		for(i = 0; i <n; i++)
		{
			dayCheck[i] = check(curDay, dayOfMonth[i]);
			weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
		}
		for(curHour = 0; curHour <= 23; curHour++)
		{
			for(i = 0; i < n; i++)
				hourCheck[i] = check(curHour, hours[i]);
				
			for(curMin = 0; curMin <= 59; curMin++)
				for(i = 0; i < n; i++)
					if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
						print(startY, startM, curDay, curHour, curMin, command[i]);
		}
	}
	
	for(curMonth = startM+1; curMonth<= 12; curMonth++)
	{
			for(i = 0; i < n; i++)
				monthCheck[i] = check(curMonth, month[i]);
			
			for(curDay = 1; curDay <= monthDays[curMonth]; curDay++)
			{
				curWeekDay = (curWeekDay + 1) % 7;
				for(i = 0; i <n; i++)
				{
					dayCheck[i] = check(curDay, dayOfMonth[i]);
					weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
				}
				for(curHour = 0; curHour <= 23; curHour++)
				{
					for(i = 0; i <n; i++)
						hourCheck[i] = check(curHour, hours[i]);
					for(curMin = 0; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
								print(startY, curMonth, curDay, curHour, curMin, command[i]);
				}
			}
	}
	
	for(curYear = startY+1; curYear < endY; curYear++)
	{	
		if((curYear%4==0 && curYear%100!=0) || curYear%400==0)
			monthDays[2]  = 29;
		else 
			monthDays[2] = 28;
			
		for(curMonth = 1; curMonth <= 12; curMonth++)
		{
			for(i = 0; i < n; i++)
				monthCheck[i] = check(curMonth, month[i]);
			
			for(curDay = 1; curDay <= monthDays[curMonth]; curDay++)
			{
				curWeekDay = (curWeekDay + 1) % 7;
				for(i = 0; i <n; i++)
				{
					dayCheck[i] = check(curDay, dayOfMonth[i]);
					weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
				}
				for(curHour = 0; curHour <= 23; curHour++)
				{
					for(i = 0; i <n; i++)
						hourCheck[i] = check(curHour, hours[i]);
					for(curMin = 0; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
								print(curYear, curMonth, curDay, curHour, curMin, command[i]);
				}
			}
		}
	}
		
	
	if((endY%4==0 && endY%100!=0) || endY%400==0)
		monthDays[2] = 29 ;
	else
		monthDays[2] = 28;
		
	for(curMonth = 1; curMonth<= endM-1; curMonth++)
	{
			for(i = 0; i < n; i++)
			{
				monthCheck[i] = check(curMonth, month[i]);
			}
			for(curDay = 1; curDay <= monthDays[curMonth]; curDay++)
			{
				curWeekDay = (curWeekDay + 1) % 7;
				for(i = 0; i <n; i++)
				{
					dayCheck[i] = check(curDay, dayOfMonth[i]);
					weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
				}
				for(curHour = 0; curHour <= 23; curHour++)
				{
					for(i = 0; i <n; i++)
						hourCheck[i] = check(curHour, hours[i]);
					for(curMin = 0; curMin <= 59; curMin++)
						for(i = 0; i < n; i++)
							if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
								print(endY, curMonth, curDay, curHour, curMin, command[i]);
				}
			}
	}	
	for(i = 0; i < n; i++)
			{
				monthCheck[i] = check(endM, month[i]);
			}
	
	for(curDay = 1; curDay <= endD-1; curDay++)
	{
		curWeekDay = (curWeekDay + 1) % 7;
		for(i = 0; i <n; i++)
		{
			dayCheck[i] = check(curDay, dayOfMonth[i]);
			weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
		}
		for(curHour = 0; curHour <= 23; curHour++)
		{
			for(i = 0; i < n; i++)
				hourCheck[i] = check(curHour, hours[i]);
				
			for(curMin = 0; curMin <= 59; curMin++)
				for(i = 0; i < n; i++)
					if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
						print(endY, endM, curDay, curHour, curMin, command[i]);
		}
	}	
	curWeekDay = (curWeekDay + 1) % 7;
		for(i = 0; i <n; i++)
		{
			dayCheck[i] = check(endD, dayOfMonth[i]);
			weekCheck[i] = check(curWeekDay, dayOfWeek[i]);
		}
	for(curHour = 0; curHour <= endH-1; curHour++)
	{
		for(i = 0; i < n; i++)
			hourCheck[i] = check(curHour, hours[i]);
			
		for(curMin = 0; curMin <= 59; curMin++)
			for(i = 0; i < n; i++)
				if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
					print(endY, endM, endD, curHour, curMin, command[i]);	
	}
	for(i = 0; i < n; i++)
			hourCheck[i] = check(endH, hours[i]);
			
	for(curMin = 0; curMin < endMin; curMin++)
		for(i = 0; i < n; i++)
			if(monthCheck[i] && dayCheck[i] && weekCheck[i] && hourCheck[i] && check(curMin, minutes[i]))
				print(endY, endM, endD, endH, curMin, command[i]);


	return 0;
}
