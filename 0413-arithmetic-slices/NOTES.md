this is a kind of question which does not seems like dp
​
in this question what we actually did was
->firstly maintain a variable prev_diff as difference between the first two elements.
->keep two variable cnt,ans to actually iterate and find out the answer.
->then iterate over the array and check whether the next pair having same difference between them or not
->if **YES** increase the cnt ... it means more elements found with same difference and we can add this to our answer
->if **NO** then we need to set the cnt to 0 and prev_diff=current_diff .... it means we are now trying to find out with this difference .
**IMPORTANT**
​
As we are going to find out hte arithmetic substrings we need to**add cnt to ans in every iteration** .
​