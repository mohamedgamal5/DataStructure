//MGD
#include <iostream>
using namespace std;
#define Max 100

// Sorts an array of strings where length of every
// string should be smaller than Max
void strcpy(char x[], char y[])
{
    int i =0;
    for(;y[i]!='\0';i++)
        x[i] = y[i];
    x[i] = '\0';
}

int strcmp(char x[], char y[])
{
    int i = 0, flag = 0;
    while (flag == 0) {
        if (x[i] > y[i]) {
            flag = 1;
        } else
        if (x[i] < y[i]) {
            flag = -1;
        } else {
            i++;
        }
    }
    return flag;
}

void Sort(char str[], int n,int index[])
{
    char arr[n][Max];
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        for(int j = i; str[j] != '\0'; j++)
        {
            arr[i][k] = str[j];
            k++;
        }
        arr[i][k] = '\0';
    }
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	char minStr[Max];
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		int min_idx = i;
		strcpy(minStr, arr[i]);
		for (j = i + 1; j < n; j++)
		{
			// If min is greater than arr[j]
			if (strcmp(minStr, arr[j]) > 0)
			{
				// Make arr[j] as minStr and update min_idx
				strcpy(minStr, arr[j]);
				min_idx = j;
			}
		}

		// Swap the found minimum element with the first element
		if (min_idx != i)
		{
			char temp[Max];
			strcpy(temp, arr[i]); //swap item[pos] and item[i]
			strcpy(arr[i], arr[min_idx]);
			strcpy(arr[min_idx], temp);
			int t;
			t=index[i];
			index[i]=index[min_idx];
			index[min_idx] = t;
		}
	}
}


class SuffixArray
{
public:
    int* order;
    char* str;
    int len = 0;
    char** txt;
    SuffixArray(char str1[])
    {
        for(int i = 0; str1[i] != '\0'; i++)
        {
            len++;
        }
        str = new char[len];
        order = new int[len];
        txt = new char*[len];
        for(int i = 0; i < len; i++)
        {
            txt[i] = new char[Max];
        }
        for(int i = 0; i < len; i++)
        {
            str[i] = str1[i];
        }
        str[len] ='\0';
    }
    void ConstructUsingPrefixDoubling()
    {
         for(int i = 0;i<len;i++)
        {
            int k = 0;
            for(int j=i;str[j]!='\0';j++)
            {
                txt[i][k] = str[j];
                k++;
            }
            order[i] = i;
            txt[i][k] = '\0';
        }

        Sort(str, len, order);
    }
    void Print()
    {
        cout << "Print : ";
        for(int i = 0; i < len; i++)
            cout << order[i] << " ";
        cout << endl;
    }




};
int main()
{
    SuffixArray t("ACGACTACGATAAC$");
    t.ConstructUsingPrefixDoubling();
    t.Print(); // Prints:  14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
    return 0;
}


