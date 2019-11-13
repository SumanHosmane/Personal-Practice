string = "{[(6gdh)]}"
stack =[]

for i in range(0,len(string)):
  if ((string[i] == '(') or (string[i] == '{') or (string[i] == '[')):
    stack.append(string[i])
  elif ((string[i] == '}') or (string[i] == ')') or (string[i] == ']')):
    if ((string[i] == '}') and (stack[len(stack)-1] == '{')):
      stack.pop()
    elif ((string[i] == ')') and (stack[len(stack)-1] == '(')):
      stack.pop()
    elif ((string[i] == ']') and (stack[len(stack)-1] == '[')):
      stack.pop()
    else:
	    break
  else:
    continue
if(len(stack) == 0):
  print("Balanced")
else:
  print("Unbalanced")