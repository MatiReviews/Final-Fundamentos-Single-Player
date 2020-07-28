void DoubleXpActive(bool& doubleMode, int& doubleModeClock, int& modMode)
{
    if (doubleMode)
    {
        if (doubleModeClock > 0)
        {
            doubleModeClock--;

            if (doubleModeClock == 0)
            {
                doubleMode = false;
                modMode = 0;
                doubleModeClock = 40;
            }
        }
    }
}