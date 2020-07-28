void PointsCounterActive(int& points, bool doublePoints)
{
    if (doublePoints != true)
    {
        points++;
    }
    else
    {
        points += 2;
    }
};