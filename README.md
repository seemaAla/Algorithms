#Overview
This project analyzes monthly quality logs from a pharmaceutical factory in Dublin. The logs track production issues across 4 certified production lines, where multiple products are manufactured under strict quality standards.

The goal is to assist management by providing efficient reports and insights from the quality logs using algorithms optimized for large datasets.


#Tasks
Task 1: create data for 4 line logs, and order each line log depeneding on their product_ID, issue_code and Date using a sorting algorithm of O(n(logn)) or better ----used merge sort
Task 2: combine all 4 line logs into one list, and sort them based on product_ID with time complexity of O(n)----used merge as already sorted
Task 3: search for the earliest occurrence of an issue code for a given product id across all lines, time complexity O(log(n))----used Binary search
Task 4: Provide a report which summarises the number of issues reported for a product across all lines, in O(n) or better-----linear search-- using for loop 
