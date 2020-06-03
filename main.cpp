#include <iostream>
#include <sstream>
using namespace std;
int convToInt(string strArgument)
    {
        stringstream ssConvert;
        int intValue = 0;
        ssConvert << strArgument;
        ssConvert >> intValue;
        if(ssConvert.fail())
        {
            cerr << "Conversion of " << strArgument << " has failed." << endl;
            exit(-1);
        }
        return intValue;
    }
int main(int argc,char* argv[])
{
    /**Exit Code*/
    const int SUCCESS = 0;
    const int ERROR_CMD_ARG = -2;
    /**Checking CMD ARG*/
    if(argc <=1)
    {
       cerr << "Incorrect Number of CMD arguments. Usage: <Sequence>";
       exit(ERROR_CMD_ARG);
    }
    /**Converting CMD arguments to Int*/
    int intSequence[argc];
    int intModalValues[argc];
    /**Initialising Arry*/
    for(int s =0;s < argc;s++)
    {
        intSequence[s] = 0;
        intModalValues[s] = 0;
    }
    /**Converting to integer*/
    for(int s =1;s < argc;s++)
    {
        intSequence[s] = convToInt(argv[s]);
    }
    /**Calculating Modal value*/
    int intCount = 1;
    int intModalNumber = 0 ;
    int intResult =0;
    for(int i = 0 ;i < argc;i++)
    {
            int localCount = 0;
            for(int j = 0 ; j < argc ; j++)
            {
                if(intSequence[i] == intSequence[j])
                {
                    localCount++;
                }
            }
            if(localCount > intCount)
            {
                intResult = intSequence[i];
                cout << intResult << " ";
            }
    }

    return SUCCESS;
}
