struct data_series {
	double		avg;
	uint64_t	count;
};

double update_avg(struct data_series *ds, double new_value)
{
	ds->avg = ds->avg + (new_value - ds->avg) / ds->count;
	ds->count++;
}

double calculate_avg(struct data_series *ds, double *data, int sz)
{
	double sum = 0.0;
	int i;

	for (i = 0; i < sz; i++)
		sum += data[i];
	
	ds->avg = sum / sz;
	ds->count = sz;
}
