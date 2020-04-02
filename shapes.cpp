#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class shape
{
    protected:
        string name;
    public:
        shape(string n){name = n;}
        virtual float getarea(){}
        virtual void display(){}
};

class point : public shape
{
    private:
        int x,y;
    public:
        point(string name,int a,int b):shape(name)
        {
            x=a;
            y=b;
        }
        void display()
        {
            cout<<"Details :\n";
            cout<<"\t"<<"Name : "<<name<<"\n";
            cout<<"\t"<<"Value(x,y): "<<"("<<x<<","<<y<<")"<<"\n";
        }
} ;

class line : public shape
{
    private :
        int x1,x2,y1,y2,slope;
    public :
        line(string name,int a,int b,int c,int d):shape(name)
        {
            x1 = a;
            y1 = b;
            x2 = c;
            y2 = d;
        }
        int findslope()
        {
            slope = (y2-y1)/(x2-x1);
            return slope;
        }
        void display()
        {
          cout<<"Details :\n";
          cout<<"\t"<<"Name  : "<<name<<"\n";
          cout<<"\t"<<"Values: "<<"(x1,y1)->"<<"("<<x1<<","<<y1<<")"<<"(x2,y2)->"<<"("<<x2<<","<<y2<<")"<<"\n";
          cout<<"\t"<<"slope :"<< findslope();
        }
};

class rectangle :public shape
{
    private:
        int length,breadth;
    public:
        rectangle(string name,int a,int b):shape(name)
        {
            length = a;
            breadth = b;
        }
        float getarea()
        {
            return(length*breadth);
        }
        void display()
        {
            cout<<"Details :\n";
            cout<<"\t"<<"Name    :"<<name<<"\n";
            cout<<"\t"<<"Breadth :"<<breadth<<"\n";
            cout<<"\t"<<"Length  :"<<length<<"\n";
            cout<<"\t"<<"Area    :"<<getarea()<<"\n";
        }
};

class circle :public shape
{
    private :
        int radius;
    public :
        circle(string name,int a):shape(name)
        {
            radius = a;
        }
        float getarea()
        {
            return(3.14*radius*radius);
        }
        void display()
        {
            cout<<"Details :\n";
            cout<<"\t"<<"Name   :"<<name<<"\n";
            cout<<"\t"<<"Radius :"<<radius<<"\n";
            cout<<"\t"<<"Area   :"<<getarea()<<"\n";
            cout<<"\t"<<"Circumference :"<<2*3.14*radius<<"\n";
        }
};

class triangle : public shape
{
    private :
        int base,height;
    public :
        triangle(string name,int a,int b):shape(name)
        {
            base = b;
            height = a;
        }
        float getarea()
        {
            return(0.5*base*height);
        }
        void display()
        {
            cout<<"Details :"<<"\n";
            cout<<"\t"<<"Name   :"<<name<<"\n";
            cout<<"\t"<<"Height :"<<height<<"\n";
            cout<<"\t"<<"Base   :"<<base<<"\n";
            cout<<"\t"<<"Area   :"<<getarea()<<"\n";
        }
};

int main()
{
    shape *a[5];
    int choice,length,breadth,radius,x,y,e,b,c,d,height,base;
    cout<<"Hello\n";
    while(1)
    {
        cout<<"\nchoose:\n\t1-point\n\t2-line\n\t3-rectangle\n\t4-circle\n\t5-triangle\n\t6-exit\n";
        cin>>choice;
        switch(choice)
        {
        case 1: cout<<"\nenter point values x and y\n";
                cin>>x>>y;
                a[0] = new point("point",x,y);
                a[0]->display();
                break;
        case 2: cout<<"\nenter 2 point values in the format(x,y)\n";
                cin>>e>>b>>c>>d;
                a[1] = new line("line",e,b,c,d);
                a[1]->display();
                break;
        case 3: cout<<"\nenter length and breadth values\n";
                cin>>length>>breadth;
                a[2] = new rectangle("rectangle",length,breadth);
                a[2]->display();
                break;
        case 4: cout<<"\nenter the radius value\n";
                cin>>radius;
                a[3] = new circle("circle",radius);
                a[3]->display();
                break;
        case 5: cout<<"\nenter height and base values\n";
                cin>>height>>base;
                a[4] = new triangle("triangle",height,base);
                a[4]->display();
                break;
        case 6: exit(0);
        default : cout<<"invalid choice\n";
                  break;
        }
    }
    return 0;
}
