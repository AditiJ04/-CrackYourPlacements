by_manager = employees.groupby('reports_to', as_index=False).agg(
    reports_count=('employee_id', 'size'),
    average_age=('age', 'mean')
)