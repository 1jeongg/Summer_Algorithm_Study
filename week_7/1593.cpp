#include<iostream>
#include<map>
using namespace std;

int kind = 0, num = 0, count = 0; 
int n, m;
string p, q;
map<char, int> origin; 
map<char, int> window;

void change(int n)		
{
	int i;
	int Start = 0, End = n-1;
 
    while(1)
    {
        if(num==kind)
		{
            bool check = true;
            
            for(i=Start; i<=End; i++)
			{
                if(window[q[i]] != origin[q[i]])
				{
                    check = false;
                    break;
                }
            }
            if(check) 
			count++;
        }
       
       	if(window[q[Start]] != 1) window[q[Start]]--; 		// Start값 조정 
		else
		{
            window.erase(q[Start]);
            num--;
        }
        Start++;
 
 
        End++;					// End값 조정 
        
        if(End>=m) 
		break;
    
        if(window.count(q[End]) != 0) window[q[End]]++;
        else
		{
            window[q[End]] = 1;
            num++;
        }
    }    
}

int main()
{
	int i;
    cin>>n>>m;	
    cin>>p>>q;   
 
    for(i=0; i<n; i++) 		
	{
        if(origin.count(p[i]) != 0) origin[p[i]]++;
        else
		{
            origin[p[i]] = 1;
            kind++;
        }
    }
    
    for(i=0; i<n; i++)
	{
        if(window.count(q[i])!=0) window[q[i]]++; 
		else
		{
            window[q[i]] = 1;
            num++;
    	}
    }
    
    change(n);
    cout<<count;
	  
    return 0;
}
