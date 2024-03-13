PUSH(HEAD, DATA, PRIORITY):

Step 1: Create new node with DATA and PRIORITY 
Step 2: Check if HEAD has lower priority. If true follow Steps 3-4 and end. Else goto Step 5. 
Step 3: NEW -> NEXT = HEAD 
Step 4: HEAD = NEW 
Step 5: Set TEMP to head of the list 
Step 6: While TEMP -> NEXT != NULL and TEMP -> NEXT -> PRIORITY > PRIORITY 
Step 7: TEMP = TEMP -> NEXT 
[END OF LOOP] 
Step 8: NEW -> NEXT = TEMP -> NEXT 
Step 9: TEMP -> NEXT = NEW 
Step 10: End
POP(HEAD):

Step 1: Set the head of the list to the next node in the list. HEAD = HEAD -> NEXT. 
Step 2: Free the node at the head of the list 
Step 3: End
PEEK(HEAD): 

Step 1: Return HEAD -> DATA 
Step 2: End
