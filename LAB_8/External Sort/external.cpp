#include <bits/stdc++.h>
using namespace std;

#define MAX_ELEM 10000
#define pii pair<int, int>

void externalSort(FILE *inp, FILE *out)
{
    double read_write = 0;
    double sort_time = 0;

    int n = 10000000;
    int numFiles = n / MAX_ELEM;
    clock_t start, end;

    char fileName[10];
    vector<FILE *> tempOut;

    for (int i = 0; i < numFiles; i++)
    {
        snprintf(fileName, sizeof(fileName), "%d", i);

        // Time taken to open the files in write mode
        start = clock();

        FILE* fp = fopen(fileName, "w");
        
        end = clock();
        read_write += ((double)(end - start))/CLOCKS_PER_SEC;
        
        tempOut.push_back(fp);
    }

    int outFile = 0;
    bool isPresent = true;
    int *arr = (int *)malloc((MAX_ELEM + 1) * sizeof(int));

    while (isPresent)
    {   
        int size = 0;
        
        // Time taken to read from input files
        start = clock();
        for (int i = 0; i < MAX_ELEM + 1; i++)
        {   
            if (fscanf(inp, "%d ", &arr[i]) != 1)
            {
                isPresent = false;
                break;
            }
            size++;
        }
        end = clock();
        read_write += ((double)(end - start))/CLOCKS_PER_SEC;
        
        // Time taken to sort the elements in each file
        start = clock();
        sort(arr, arr + size);
        end = clock();
        sort_time += ((double)(end - start))/CLOCKS_PER_SEC;

        // Time taken to write to temporary files
        start = clock();
        for (int i = 0; i < size; i++)
        {
            fprintf(tempOut[outFile], "%d ", arr[i]);
        }
        end = clock();
        read_write += ((double)(end - start))/CLOCKS_PER_SEC;

        fclose(tempOut[outFile]);
        outFile++;
    }

    vector<FILE *> tempIn;
    for (int i = 0; i < numFiles; i++)
    {
        snprintf(fileName, sizeof(fileName), "%d", i);

        // Time taken to open the files in read mode
        start = clock();

        FILE* fp = fopen(fileName, "r");
        
        end = clock();
        read_write += ((double)(end - start))/CLOCKS_PER_SEC;
        
        tempIn.push_back(fp);
    }


    int num;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Time taken to read the first element from all temporary files
    for (int i = 0; i < numFiles; i++)
    {   
        start = clock();

        if (fscanf(tempIn[i], "%d ", &num) != 1)
            break;
        
        end = clock();
        read_write += ((double)(end - start))/CLOCKS_PER_SEC;

        pq.push({num, i});
    }

    while (pq.size())
    {
        pii min_num = pq.top();
        pq.pop();

        // Time taken to write to output file and read the next element
        start = clock();

        fprintf(out, "%d ", min_num.first);

        if (fscanf(tempIn[min_num.second], "%d ", &num) != 1)
        {
            fclose(tempIn[min_num.second]);

            end = clock();
            read_write += ((double)(end - start))/CLOCKS_PER_SEC;

            snprintf(fileName, sizeof(fileName), "%d", min_num.second);
            remove(fileName);
            continue;
        }
        
        end = clock();
        read_write += ((double)(end - start))/CLOCKS_PER_SEC;

        pq.push({num, min_num.second});
    }

    cout << "Time used for reading and writing the files: " << read_write << setprecision(6) << endl;
    cout << "Time used for sorting the files: " << sort_time << setprecision(6) << endl;
}

int main()
{
    FILE *inp = fopen("demofile.txt", "r");
    FILE *out = fopen("sortfile.txt", "w");

    externalSort(inp, out);

    fclose(inp);
    fclose(out);
}