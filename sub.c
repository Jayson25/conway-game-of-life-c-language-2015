/*void judgement()
{
    if (loop >= 1)
        {
            for (i=1; i<hauteur+1; i++)
            {
                for(j=1; j<largeur+1; j++)
                {
                    int neighbor = 0;
                        if ((mappage[i-1][j-1]=='+')||(mappage[i-1][j-1]=='0'))
                        {
                            neighbor++;
                        }
                        if ((mappage[i][j-1]=='+')||(mappage[i][j-1]=='0'))
                        {
                            neighbor++;
                        }
                        if ((mappage[i+1][j-1]=='+')||(mappage[i+1][j-1]=='0'))
                        {
                            neighbor++;
                        }
                        if ((mappage[i-1][j]=='+')||(mappage[i-1][j]=='0'))
                        {
                            neighbor++;
                        }
                        if ((mappage[i+1][j]=='+')||(mappage[i+1][j]=='0'))
                        {
                            neighbor++;
                        }
                        if ((mappage[i-1][j+1]=='+')||(mappage[i-1][j+1]=='0'))
                        {
                            neighbor++;
                        }
                        if ((mappage[i][j+1]=='+')||(mappage[i][j+1]=='0'))
                        {
                            neighbor++;
                        }
                        if ((mappage[i+1][j+1]=='+')||(mappage[i+1][j+1]=='0'))
                        {
                            neighbor++;
                        }

                        if ((neighbor == 2)||(neighbor == 3))
                        {
                            if ((mappage[i][j]=='+')||(mappage[i][j]=='0'))
                            {
                                mappage[i][j]='+';
                            }

                            else if (mappage[i][j]='-')
                            {
                                mappage[i][j]='0';
                            }
                        }

                        else
                            {
                                mappage[i][j]='-';
                            }
                }
            }
        }
}*/
