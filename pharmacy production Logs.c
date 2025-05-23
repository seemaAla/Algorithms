
#include <stdio.h>
#include <stdlib.h>


//symbolic names
#define SIZE_LIST 6
#define NUM_PRODUCTS 24


//structure templates
//for task 1
struct Date {
    int day;
    int hour;
    int minutes;
};

//for task 1
typedef struct Report {
    int product_ID;
    int issue_code;
    struct Date LOG_DATE;
} Report;

//for task 2
typedef struct Issue_report {
    int product_ID; 
    int line_code;
    int issue_code;
} Issue_report;

//for task 4
typedef struct Count_issues {
    int product_ID;
    int num_issues;
} Count_issues;


//function signatures
void merge_sort(Report [], int, int); 
void merge_task1(Report [], int, int, int);
void printing_task1(int);
void Task1(void);
void Task2(Report [], Report [], Report [], Report []);
void merge_task2(Issue_report [], Issue_report [], Issue_report [], int);
void Task3(Issue_report []);
int binary_search(Issue_report [], int , int, int); 
void Task4(Issue_report []);



int main() 
{
    Task1();
    
    return 0;
}



//merge sorts an array recursively 
void merge_sort(Report list[], int start, int end) 
{
    if (start < end) 
    {
        int mid = (start + end) / 2;

        merge_sort(list, start, mid);
        merge_sort(list, mid + 1, end);
        merge_task1(list, start, mid, end);
    }
}//end merge_sort()

//merges two sorted arrays
void merge_task1(Report list[], int start, int mid, int end)
{
    Report temp[SIZE_LIST]; //made sure temp is also a struct variable of Report to make comparison with list[]
    int i = start;
    int k = start;
    int j = mid + 1;

    while ((i <= mid) && (j <= end)) 
    {
        if ((list[i].product_ID < list[j].product_ID) || (list[i].product_ID == list[j].product_ID && list[i].issue_code < list[j].issue_code))
        {
            //place the element of first sub_list in temp list
            temp[k++] = list[i++];
        }//end if 
        else if((list[i].product_ID == list[j].product_ID) && (list[i].issue_code == list[j].issue_code) && (list[i].LOG_DATE.day < list[j].LOG_DATE.day))
        {
            temp[k++] = list[i++];
        }//end else if
        else if((list[i].product_ID == list[j].product_ID) && (list[i].issue_code == list[j].issue_code) && (list[i].LOG_DATE.day == list[j].LOG_DATE.day) &&
                (list[i].LOG_DATE.hour < list[j].LOG_DATE.hour))
        {      
            temp[k++] = list[i++];
        }//end else if
        else if((list[i].product_ID == list[j].product_ID) && (list[i].issue_code == list[j].issue_code) && (list[i].LOG_DATE.day == list[j].LOG_DATE.day) && 
                (list[i].LOG_DATE.hour == list[j].LOG_DATE.hour) && (list[i].LOG_DATE.minutes < list[j].LOG_DATE.minutes))
        {
            temp[k++] = list[i++];
        }//end else if
        //
        else 
        {
            //place the element of second sub_list in temp list
            temp[k++] = list[j++];
        }//end else
    }//end while

    //while first sub_list not sorted yet
    while (i <= mid)
    {
        temp[k++] = list[i++];
    }//end while

    //wjile second sub_list not sorted 
    while (j <= end) 
    {
        temp[k++] = list[j++];
    }//end while

    //copy elements of array temp into original list
    for (i = start; i <= end; i++) 
    {
        list[i] = temp[i];
    }//end for
    
}//end merge() function

//function that prints formatted information for a given log number
void printing_task1(int i)
{

    printf("\n*** sorted: LINE LOG %d ***\n", i);
    
    printf("product_ID:\tIssue_code:\t(Day,Hour,Minutes):\n");

}

void Task1()
{
    //line log 1
    Report line_log1[SIZE_LIST] = {{103, 1333, {5, 12, 6}},
                                   {102, 1339, {4, 8, 3}},
                                   {102, 1339, {3, 9, 8}},
                                   {102, 1337, {4, 8, 59}},
                                   {103, 1339, {7, 8, 30}},
                                   {102, 1333, {5, 11, 45}} 
                                  };

    //line log 2
    Report line_log2[SIZE_LIST] = {{204, 1333, {5, 12, 6}},
                                   {204, 2339, {29, 12, 57}},
                                   {206, 2937, {30, 9, 8}},
                                   {206, 2937, {1, 23, 59}},
                                   {206, 2937, {1, 7, 24}},
                                   {204, 2833, {5, 11, 45}} 
                                  };

    //line log 3
    Report line_log3[SIZE_LIST] = {{301, 3000, {5, 12, 6}},
                                   {305, 3211, {4, 8, 3}},
                                   {301, 3211, {4, 9, 8}},
                                   {305, 3443, {4, 8, 59}},
                                   {305, 3777, {7, 8, 30}},
                                   {301, 3579, {5, 11, 45}} 
                                  };

    //line log 4
    Report line_log4[SIZE_LIST] = {{407, 4333, {11, 0, 1}},
                                   {400, 4339, {9, 12, 57}},
                                   {400, 4937, {30, 5, 19}},
                                   {400, 4925, {1, 3, 9}},
                                   {404, 4937, {1, 5, 49}},
                                   {404, 4831, {5, 5, 2}} 
                                  };

    //----LOG LINE 1----
    //line log 1 calling function and printing
    merge_sort(line_log1, 0, SIZE_LIST - 1); 

    printf("\n\n<<<<<< Task 1 >>>>>>\n\n");

    //printing title 
    printing_task1(1);

    //Printing sorted array for line log 1
    for (int i = 0; i < SIZE_LIST; i++) 
    {
        printf("%d\t\t%d\t\t%d,%d,%d\n", line_log1[i].product_ID, line_log1[i].issue_code, line_log1[i].LOG_DATE.day, line_log1[i].LOG_DATE.hour, line_log1[i].LOG_DATE.minutes);
    }//end for loop

    //----LOG LINE 2----
    //line log 2 calling function and printing
    merge_sort(line_log2, 0, SIZE_LIST - 1);

    printing_task1(2);

    //Printing sorted array for line log 2
    for (int i = 0; i < SIZE_LIST; i++) 
    {
        printf("%d\t\t%d\t\t%d,%d,%d\n", line_log2[i].product_ID, line_log2[i].issue_code, line_log2[i].LOG_DATE.day, line_log2[i].LOG_DATE.hour, line_log2[i].LOG_DATE.minutes);
    }//end for

    //----LOG LINE 3----
    //line log 3 calling function and printing
    merge_sort(line_log3, 0, SIZE_LIST - 1);

    printing_task1(3);

    //Printing sorted array for line log 2
    for (int i = 0; i < SIZE_LIST; i++) 
    {
        printf("%d\t\t%d\t\t%d,%d,%d\n", line_log3[i].product_ID, line_log3[i].issue_code, line_log3[i].LOG_DATE.day, line_log3[i].LOG_DATE.hour, line_log3[i].LOG_DATE.minutes);
    }//end for

    //----LOG LINE 3----
    //line log 3 calling function and printing
    merge_sort(line_log4, 0, SIZE_LIST - 1);

    printing_task1(4);

    //Printing sorted array for line log 2
    for (int i = 0; i < SIZE_LIST; i++) 
    {
        printf("%d\t\t%d\t\t%d,%d,%d\n", line_log4[i].product_ID, line_log4[i].issue_code, line_log4[i].LOG_DATE.day, line_log4[i].LOG_DATE.hour, line_log4[i].LOG_DATE.minutes);
    }//end for

    //calling Task2() fucntion
    Task2(line_log1, line_log2, line_log3, line_log4);

}//end of Task1() function



//combines all log lines into one list containing "product_ID, line_code and issue_code" using merge()
//it copies data from structure 'Report line_log1/2/3/4' to structure 'Combined_lines line_1/2/3/4'
//then assigns data to line_code. Finally calls merge_task2() to combine those log lines and sort them by product_ID
void Task2(Report line_log1[], Report line_log2[], Report line_log3[], Report line_log4[])
{
    //creating variables in structure Combined_lines
    Issue_report line_1[SIZE_LIST], line_2[SIZE_LIST], line_3[SIZE_LIST], line_4[SIZE_LIST];

    //using a for loop to copy data form a Report structure to Combined_list struct
    for(int i=0; i<SIZE_LIST; i++)
    {
        //copy data from line_log1 into line_1
        line_1[i].product_ID = line_log1[i].product_ID;
        line_1[i].issue_code = line_log1[i].issue_code;

        //assign data to line_1 line_code
        line_1[i].line_code = 1;

        //copy data from line_log2 into line_2
        line_2[i].product_ID = line_log2[i].product_ID;
        line_2[i].issue_code = line_log2[i].issue_code;

        //assign data to line_2 line_code
        line_2[i].line_code = 2;

        //copy data from line_log3 into line_3
        line_3[i].product_ID = line_log3[i].product_ID;
        line_3[i].issue_code = line_log3[i].issue_code;

        //assign data to line_3 line_code
        line_3[i].line_code = 3;

        //copy data from line_log4 into line_4
        line_4[i].product_ID = line_log4[i].product_ID;
        line_4[i].issue_code = line_log4[i].issue_code;

        //assign data to line_4 line_code
        line_4[i].line_code = 4;
    }//end for loop


    //creating variables in structure Issue_report to store our two different merged lists 
    Issue_report sub_list1[SIZE_LIST*2], sub_list2[SIZE_LIST*2], final_list[SIZE_LIST*4];

    //MERGE line_1 and line_2 and save in variable sub_list1 of structure Issue_report
    merge_task2(line_1, line_2, sub_list1, SIZE_LIST*2);

    //MERGE line_3 and line_4 and save in variable sub_list2 of structure Issue_report
    merge_task2(line_3, line_4, sub_list2, SIZE_LIST*2);

    //MERGE sub_list1 and sub_list2 and save in final_list
    merge_task2(sub_list1, sub_list2, final_list, SIZE_LIST*4);

    printf("\n\n<<<<<< Task 2 >>>>>>\n\n");
    printf("Product_ID\tLine_code\tIssue_code\n");

    //printing combined sorted 4 log lines, hence SIZE_LIST*4
    for(int i=0; i<(SIZE_LIST)*4; i++)
    {
        printf("%d\t\t%d\t\t%d\n", final_list[i].product_ID, final_list[i].line_code, final_list[i].issue_code);
    }//end for loop

    //calling Task3()
    Task3(final_list);
    
    
}//end of Task2() function

//merges 2 sorted lists from Issue_report structure into a final_list. size is the size final_list array
void merge_task2(Issue_report list_1[], Issue_report list_2[], Issue_report final_list[], int size)
{
    //i keeps track of first list--- j of second list---- k of final list
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < size/2) && (j < size/2)) 
    {
        //sort by product_ID 
        if ((list_1[i].product_ID < list_2[j].product_ID))
        {
            final_list[k++] = list_1[i++];
        }//end if 
        else 
        {
            final_list[k++] = list_2[j++];
        }//end else
    }//end while

    while (i < size/2)
    {
        final_list[k++] = list_1[i++];
    }//end while

    while (j < size/2) 
    {
        final_list[k++] = list_2[j++];
    }//end while


}//end merge_task2() function



void Task3(Issue_report final_list [])
{
    int searched_product_ID;
    int result_index;

    printf("\n\n<<<<<< Task 3 >>>>>>\n\n");
    printf("---search for the earliest occurrence of an Issue code for a given Product ID across all lines---\n\n");
    printf("search for Product_ID: ");
    scanf("%d", &searched_product_ID);

    //calling binary_search function
    //saving result: the 'index' of searched_product_ID in result_index
    result_index = binary_search(final_list, searched_product_ID, 0, (SIZE_LIST*4)-1);

    //printf("result index: %d\n", result_index);


    //to print out whether searched_product_ID was found or not
    if(result_index >= 0)
    {
        printf("Issue code is: %d\nline_code = %d", final_list[result_index].issue_code, final_list[result_index].line_code);
    }//end if
    else
    {
        printf("Issue code was not found");
    }//end else

    //calling Task4()
    Task4(final_list);

}//end Task3() function

//finds the INDEX of a searched element in a sorted list by contninuously splitting function and searching for that element
int binary_search(Issue_report list [], int element, int first, int last)  //fisrt index and last index in array
{
    //if size of array is one or more
    if(last >= first)
    {
        int mid = first + (last-first)/2;   

        //element in the mid number and its found
        if(list[mid].product_ID == element)
        {
            //if mid is first index of list OR the element before it is not the element searched we know its the first occurrence
            if(mid == first || list[mid-1].product_ID != element)
            {
                return mid;
            }//end inner if
            //else look more left half to find the first occurrence
            else
            {
                return  binary_search(list, element, first, mid-1);
            }
            
        }//end if 
        //element must be on left of mid 
        else if(list[mid].product_ID > element)
        {
            return binary_search(list, element, first, mid-1);
        }//end else if
        //else element must be on the right of mid
        else
        {
            return binary_search(list, element, mid+1, last);
        }//end else if
    }//end outer if

    //if element not found it returns -1
    return -1;
    
}//end binary_search() function



void Task4(Issue_report final_list [])
{
    int count = 0;
    //i iterates through final_list in Issue_report structure, while j iterates through products_list in Count_issues structure
    int i, j;
    int temp = final_list[0].product_ID; 

    //creating variable in Count_issues structure
    //give products_list 24 spaces as all might be unique product IDs
    Count_issues products_list[NUM_PRODUCTS]; 

    //iterates over all final_list and checks how many unique product_IDs there are and counts them saving answer into products_list
    for(i=0, j=0; i<= NUM_PRODUCTS; i++)
    {
        if(temp == final_list[i].product_ID)
        {
            count++;
            //printf("%d  %d\n", products_list[j].product_ID, products_list[j].num_issues);
        }//end if
        else
        {
            products_list[j].product_ID = final_list[i-1].product_ID;
            products_list[j].num_issues = count;
            temp = final_list[i].product_ID;
            //count is 1 not 0: to count new number
            count = 1;
            j++;
        }//end else
    }//end for loop

    printf("\n\n\n<<<<<< Task 4 >>>>>>\n\n");
    printf("---Summary of number of issues reported for a product across all lines---\n\n");

    //prints the summary of number of issues reported for a product across all lines.
    for(i=0; i<9; i++)
    {
        printf("product_ID: %d  Issues_reported: %d\n", products_list[i].product_ID, products_list[i].num_issues);
    }
   
    
}//end Task4() function
