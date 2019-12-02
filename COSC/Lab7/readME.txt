(a)  What is the theoretical time complexity of your sorting algorithms (best and worst case), in terms
  of the array size?
(b)  How does the absolute timing scale with the number of elements in the array?  The size of the
  elements?  Can you use the data collected to rectify this with the theoretical time complexity?
    For example:  if you double the size of an array, does Selection Sort take four times longer?
(c)  Aggregate your data into a graph of the complexity for the various array sizes, for example with
  a spreadsheet program like LibreOffice Calc or Microsoft Word.
(d)  How do the algorithms perform in different cases?  What is the best and worst case, according to
  your own test results?


(a) BubbleSort - worst: n^2
                 best: n
    InsertionSort - worst: n^2
                    best: n
    SelectionSort - (n-1)

(b) n is the number of elemnts so the more you have to more time
  BubbleSort - Worst: n^2 so if you increase n by 2 is will take 4 time as long
               Best: n if you increase it by 2 then it will run for two times the time
  InsertionSort - Worst: n^2 if you increase the amount of numbers (2n) then it will take 4 times the amount of time
                   Best: n if you increase the number of elements by 2 (2n) then it will take 2 times the times
  SelectionSort - Best/Worst: if you increase the number of elements by 2 (2n) then it will take ((2n)-1) so it will take two times the time

(d)
BubbleSort - Best was the presorted array and the worst was the reverse sorted array
InsertionSort - Best was the the presorted array and the worst was the reversed sorted array.
SelectionSort - Best and worst were any of them, the sort went through every element minus 1 no matter what and resorted
