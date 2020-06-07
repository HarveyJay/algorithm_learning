//减法
void minus(char* a, char* b, char* dest)
{
    char value = '\0',
        valueA,
        valueB;
    short carry = 0;    
    int lengthOfA = strlen(a),
        lengthOfB = strlen(b),
        len = lengthOfA > lengthOfB ? lengthOfA : lengthOfB;
    char result[len+1];

    result[len] = '\0';
    while (lengthOfA > 0 || lengthOfB > 0)
    {
        valueA = lengthOfA <=0 ? '0' : a[--lengthOfA];
        valueB = lengthOfB <=0 ? '0' : b[--lengthOfB];   
        value = valueA - valueB - carry + '0';

        if (value < '0')
        {
            value += 10;
            carry = 1;
        } 
        else {
            carry = 0;
        }

        result[len--] = value;
    }

    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        if (result[i] > '0')
        {
            break;
        }  
    }
    
    while (i < len)
    {
        dest[j++] = result[i++]; 
    }
}