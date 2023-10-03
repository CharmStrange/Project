from faker import Faker
import pandas as pd
import random

repeat_count = 1250

fake= Faker('ko_KR')
Faker.seed()

def make_dummies() :
    names = [ fake.name() for i in range(repeat_count) ]
    emails = [ fake.unique.free_email() for i in range(repeat_count) ]
    ages = [ random.randint(20, 60) for i in range(repeat_count) ]
    memberships = [ random.randint(0, 2) for i in range(repeat_count) ]
    assigned_dates = [fake.date_between(start_date = '-1y', end_date ='today') for i in range(repeat_count)]
    df = pd.DataFrame(zip(names, emails, ages, memberships, assigned_dates), columns=['이름', '이메일', '나이', '멤버십_등급', '가입일'])
    return df
