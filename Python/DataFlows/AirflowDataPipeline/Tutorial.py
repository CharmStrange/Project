from datetime import datetime, timedelta
from airflow import DAG
from airflow.operators.python_operator import PythonOperator

# 기본 설정
default_args = {
    'owner': 'CharmStrange',
    'start_date': datetime(2023, 10, 26),
}

Dag = DAG(
    dag_id = 'CoLab_Airflow', 
    default_args = default_args,  
    schedule_interval = '@once'
)

def func1(*param) :
    pass

def func2(*param) :
    pass

task1 = PythonOperator(
    task_id = 'Task1',
    python_callable=func1,
    provide_context=True,
    dag = Dag    
)

task2 = PythonOperator(
    task_id = 'Task2',
    python_callable=func1,
    provide_context=True,
    dag = Dag    
)

task1 >> task2
