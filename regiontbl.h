#include <cmath>
#include <iostream>
// -------------------------- Global Constants
const int RED=0;
const int GREEN=1;
const int BLUE=2;
const int NUM_PIXEL=3;

const int MAX_IMG_WIDTH = 2000;
const int MAX_IMG_HEIGHT = 2000;
const int MAX_REGIONS = 50000;



//--------------------------- Threshold Function

//----------------------------  Pixel class to hold values for a pixel
class pixel
{
public:
    long int h;
    long int w;
    float r;
    float g;
    float b;
    int region;
	
    pixel()     //constructor
    {
        h=-1;
        w=-1;
        r=-1;
        g=-1;
        b=-1;
        region = -1;
    }
	
    void print() //print func
    {
        std::cout<<h<<","<<w<<" : "<<r<<","<<g<<","<<b<<": "<<region<<std::endl;
    }
};


//------------------------------  Queue Implementation
const int Q_SIZE = MAX_IMG_WIDTH * MAX_IMG_HEIGHT ;
class Queue
{
 public:
        int front;
        int rear;
        pixel pix[Q_SIZE];

        Queue()
        {
            front=0;
            rear=0;
            for(int i=0;i<Q_SIZE;i++)
            {
                pix[i].h = -1;
                pix[i].w = -1;
            }
        }

        void print()
        {
            std::cout<<"\n---QUEUE---\n";
            std::cout<<"[";
            for(int i=front; i<=rear ; i++)
            {
                std::cout<<"("<<pix[i].h << "," << pix[i].w<<"), ";

            }
            std::cout<<"]";
        }

        int insert(int h, int w)
        {

            if(rear >= Q_SIZE)
            {
                std::cout<<"Queue Full";
                system("PAUSE");
                exit(1);
            }
            else
            {
                pix[rear].h=h;
                pix[rear].w=w;
                rear++;
                return 0;
            }
            return -1;
        }


        int remove(pixel &ret)
        {
            if(front == rear)
            {
                std::cout<<"\nQueue empty.. ERROR";
                system("PAUSE");
                exit(1);
            }
            else
            {
                ret.h=pix[front].h;
                ret.w=pix[front].w;
                front++;
                return 0;
            }
            return -1;
        }


        bool isempty()
        {
                if(front == rear)
                {
                        return true;
                }
                return false;
        }
                          /**sets r and f to point to zero location*/
        void empty()
        {
            front = 0;
            rear = 0;
        }
}; //Todo: remove as global later.


//------------------------------- Region Table Structure to hold region and colour details of all pixels
class Photo
{
private:
            // Image variables
    int img_width;
    int img_height;
    int img_step;
    int img_channels;
    long int img_total_regions;

            //Internal variables or constants
    int free_ht; //variable tells the img_height till where all pixels are bound...is used to find free pixels faster during segmentation.
    
            //Internal data structures
    pixel img_data[MAX_IMG_WIDTH][MAX_IMG_HEIGHT]; //will contain region details and pixel colours.
    float img_region[MAX_REGIONS][4]; // every row is [ SUM OF RED COMPONENT ][ SUM OF G][ SUM OF B ][ NUM OF PIXELS IN img_region ]     and each row index is the region no.
    Queue QUE;
	int THRESHOLD ;

public: //todo make these private
    
    Photo()
    {
            img_width=0;
            img_height=0;
            img_step=0;
            img_channels=0;
            img_total_regions=0;
			THRESHOLD=40;
            free_ht=0;

            for(int ht=0; ht<img_height ;ht++)
                for(int wt=0; wt<img_width ;wt++)
                {
                        img_data[ht][wt].h=-1; // not used here in regtbl as its indexed by array index [][]
                        img_data[ht][wt].w=-1; // not used here in regtbl as its indexed by array index [][]
                        img_data[ht][wt].r=-1;
                        img_data[ht][wt].g=-1;
                        img_data[ht][wt].b=-1;
                        img_data[ht][wt].region=-1;
                }

            for(int i=0; i<MAX_REGIONS ;i++)
            {
                img_region[i][RED]=0.0;
                img_region[i][GREEN]=0.0;
                img_region[i][BLUE]=0.0;
                img_region[i][NUM_PIXEL]=0.0;
            }
    }
	void setThreshold(int i)
	{
		THRESHOLD = i;
	}
    void convertFromCV(const IplImage* img)
    {
        uchar* data = (uchar*)img -> imageData;

        img_height = img->height;
        img_width = img->width;
        img_step      = img->widthStep;
        img_channels  = img->nChannels;

        if (img_height > MAX_IMG_HEIGHT || img_width > MAX_IMG_WIDTH || img_channels > 3) //todo: chk comparison
            {
                std::cout<<"\nERROR: Max dimensions exceeded";
                system("PAUSE");
                exit(1);
            }

        std::cout<<"\nMaking region table.";
        for(int h=0; h < img_height ;h++)
            for(int w=0; w < img_width ;w++)
            {
                img_data[h][w].r = data[h*img->widthStep + w*img->nChannels + RED];
                img_data[h][w].g = data[h*img->widthStep + w*img->nChannels + GREEN];
                img_data[h][w].b = data[h*img->widthStep + w*img->nChannels + BLUE];
            }

    }

    void convertToCV(IplImage* outimg)
    {
        uchar* outdata = (uchar*) outimg->imageData;
        //write back the averaged color into outfile.
        for(int h=0 ; h < img_height ; h++)
            for(int w=0 ; w < img_width ; w++)
            {
                outdata[h*img_step + w*img_channels + RED] = int(img_data[h][w].r);
                outdata[h*img_step + w*img_channels + GREEN] = int(img_data[h][w].g);
                outdata[h*img_step + w*img_channels + BLUE] = int(img_data[h][w].b);
            }

    }

// Returns a free pixel that doesnt belong to any region
    int get_free_pixel(pixel &pix)
    {
        for(int h=free_ht; h<img_height ;h++)
        {
            for(int w=0; w<img_width ;w++)
            {
                if(img_data[h][w].region < 0)
                {
                       pix.h=h;
                       pix.w=w;

                       pix.r = img_data[h][w].r;
                       pix.g = img_data[h][w].g;
                       pix.b = img_data[h][w].b;
                       free_ht=h;
                       return 0;
                }
            }

        }
    return -1;
    }


//Function  adds good neigbhours to the same region and also adds the neighbours to queue for further search
//good neighbours means which are in threshold and are free
bool check_threshold(float R, float G, float B, float r, float g, float b)
{
      float thvalue = sqrt(   pow(R-r,2)  +  pow(G-g,2)    +   pow(B-b,2)   );
      //std::cout<<"THV "<<thvalue<<" - "<<R<<","<<G<<","<<B<<":"<<r<<","<<g<<","<<b<<std::endl;
      if  ( thvalue <= THRESHOLD)
        return true;
      else
        return false;
}

void add_goodn(int h,int w, int REG ,float R,float G,float B)
{
        if( (w-1 >=0)  && (h-1 >= 0) )  //checking boundary conditions
        {
            int currw = w-1 ; int currh = h-1;
                    //check threshhold and if free and not bound already
            if( check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                            // add to curr region
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }
         }

         if( (w-1 >=0))
        {
            int currw = w-1 ; int currh = h;
            if( check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }

         }

         if( (w-1 >=0)  && (h+1 < img_height ) )
        {
            int currw = w-1 ; int currh = h+1;
            if( check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }
         }

         if( (h-1 >= 0) )

        {
            int currw = w ; int currh = h-1;
            if(check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }
         }

         if((h+1 < img_height) )
        {
            int currw = w ; int currh = h+1;
            if(check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }
         }

         if( (w+1 < img_width)  && (h-1 >= 0) )
        {
            int currw = w+1 ; int currh = h-1;
            if(check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }
         }
         if( (w+1 < img_width))
        {
            int currw = w+1 ; int currh = h;
            if(check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }
         }
         if( (w+1 < img_width)  && (h+1 < img_height) )
        {
            int currw = w+1 ; int currh = h+1;
            if(check_threshold(R,G,B,img_data[currh][currw].r,img_data[currh][currw].g,img_data[currh][currw].b) == true && (img_data[currh][currw].region < 0))
                {
                    img_data[currh][currw].region = REG;
                    img_region[REG][RED] += img_data[currh][currw].r;
                    img_region[REG][GREEN] += img_data[currh][currw].g;
                    img_region[REG][BLUE] += img_data[currh][currw].b;
                    img_region[REG][NUM_PIXEL]++;
                            //add to queue and add to region
                    QUE.insert(currh,currw);
                }
         }

}

// ------------------------------- Function to grow REGIONS using 8 neighbours within threshold
    void segment()
    {

        int curr_region=0;
        while (1)
        {
            pixel seed;
            if (get_free_pixel(seed) >=0 )
            {
                QUE.empty();
                int seedw = seed.w;
                int seedh = seed.h;
                float seedr = seed.r;
                float seedg = seed.g;
                float seedb = seed.b;
                        //adding to current region and adding details to img_region
                img_data[seedh][seedw].region = curr_region;
                img_region[curr_region][RED] += img_data[seedh][seedw].r;
                img_region[curr_region][GREEN] += img_data[seedh][seedw].g;
                img_region[curr_region][BLUE] += img_data[seedh][seedw].b;
                img_region[curr_region][NUM_PIXEL]++;
                        //add good neighbours to region and also adding them to search queue
                add_goodn(seedh,seedw , curr_region , seedr, seedg, seedb);
                while (! QUE.isempty()) //QUE stores the pixels which are already in this region for further searching
                {
                    pixel curr;
                    if(QUE.remove(curr)>=0)
                        {
                            int currh = curr.h;  int currw=curr.w;
                                //look at neighbours and grow
                            add_goodn(currh,currw, curr_region , seedr, seedg, seedb);
                        }
                }
                            //grow next region
                curr_region = curr_region + 1;
            }
            else
            {
                std::cout<<"\nAll pixels are alloted to some region.";
                break;
            }

        }
        img_total_regions = curr_region-1;
        std::cout<<std::endl<<img_total_regions<<" REGIONS found. \n" ;
    }


    void avgSegmentColours()
    {
        for(int r=0;r<=img_total_regions;r++)
        {
                img_region[r][RED] /=  img_region[r][NUM_PIXEL];
                img_region[r][GREEN] /=  img_region[r][NUM_PIXEL];
                img_region[r][BLUE] /= img_region[r][NUM_PIXEL];
        }

        for(int h=0 ; h < img_height ; h++)
            for(int w=0 ; w < img_width ; w++)
            {
                img_data[h][w].r = int(img_region[img_data[h][w].region][RED]);
                img_data[h][w].g = int(img_region[img_data[h][w].region][GREEN]);
                img_data[h][w].b = int(img_region[img_data[h][w].region][BLUE]);
            }

    }

};