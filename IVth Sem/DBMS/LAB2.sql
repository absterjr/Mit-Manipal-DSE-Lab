SQL> insert into EMP values(100,'RAJESH','BTECH',1234567890,'rajesh@digisol.com','DEVELOPER',100000,null);

1 row created.

SQL> insert into EMP values(101,'RAVI','MTECH',1234567891,'ravi@digisol.com','PROJECT LEADER',110000,NULL);

1 row created.

SQL> insert into EMP values(102,'VIJAY','BTECH',1234567892,'vijay@digisol.com','PROJECT MANAGER',120000,null);

1 row created.

SQL> insert into EMP values(108,'AJAY','BTECH',1234567893,'ajay@digisol.com','TECHNICAL HEAD',130000,null);

1 row created.

SQL> insert into EMP values(110,'BHASKAR','MTECH',1234567894,'bhaskar@digisol.com','PROJECT DIRECTOR',140000,null);

1 row created.

SQL> insert into EMP values(106,'RAJ','MSC',1234567895,'raj@digisol.com','PROJECT LEADER',150000,null);

1 row created.

SQL> insert into EMP values(105,'MANISH','MCA',1234567896,'manish@digisol.com','DEVELOPER',160000,null);

1 row created.

SQL> insert into EMP values(106,'PRASAD','PHD',1234567897,'prasad@digisol.com','CEO',200000,null);
insert into EMP values(106,'PRASAD','PHD',1234567897,'prasad@digisol.com','CEO',200000,null)
*
ERROR at line 1:
ORA-00001: unique constraint (DSE108.PK_EMPNO) violated 


SQL> insert into EMP values(102,'RAKESH','MTECH',12345667898,'rakesh@digisol.com','DEVELOPER',160000,null);
insert into EMP values(102,'RAKESH','MTECH',12345667898,'rakesh@digisol.com','DEVELOPER',160000,null)
                                            *
ERROR at line 1:
ORA-01438: value larger than specified precision allowed for this column 


SQL> insert into EMP values(108,'RAKESH','MTECH',1234567898,'rakesh@digisol.com','DEVELOPER',160000,null);
insert into EMP values(108,'RAKESH','MTECH',1234567898,'rakesh@digisol.com','DEVELOPER',160000,null)
*
ERROR at line 1:
ORA-00001: unique constraint (DSE108.PK_EMPNO) violated 


SQL> insert into EMP values(109,'VENKAT','MBA',1234567899,'venkat@digisol.com','PROJECT LEADER',110000,null);
insert into EMP values(109,'VENKAT','MBA',1234567899,'venkat@digisol.com','PROJECT LEADER',110000,null)
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.VALID_QUALIF) violated 


SQL> insert into EMP values(110,'BALAJI','MBA',1234569871,'balaji@digisol.com','PROJECT DIRECTOR',140000,null);
insert into EMP values(110,'BALAJI','MBA',1234569871,'balaji@digisol.com','PROJECT DIRECTOR',140000,null)
*
ERROR at line 1:
ORA-00001: unique constraint (DSE108.PK_EMPNO) violated 


SQL> insert into EMP values(111,'RAJ','BTECH',1236547895,'nikhith@digisol.com','TECHNICAL HEAD',130000,null);

1 row created.

SQL> update emp set reports_to = 101 where empcode = 100;

1 row updated.

SQL> update emp set reports_to = 102 where empcode = 101;

1 row updated.

SQL> update emp set reports_to = 110 where empcode = 102;

1 row updated.

SQL> update emp set reports_to = 102 where empcode = 108;

1 row updated.

SQL> update emp set reports_to = 106 where empcode = 110;

1 row updated.

SQL> update emp set reports_to = 110 where empcode = 106;

1 row updated.

SQL> update emp set reports_to = 106 where empcode = 105;

1 row updated.

SQL> select * from emp;

   EMPCODE NAME       QUALIFI      PHONE EMAIL                                  
---------- ---------- ------- ---------- --------------------                   
DESIGNATION              SALARY REPORTS_TO                                      
-------------------- ---------- ----------                                      
       100 RAJESH     BTECH   1234567890 rajesh@digisol.com                     
DEVELOPER                100000        101                                      
                                                                                
       101 RAVI       MTECH   1234567891 ravi@digisol.com                       
PROJECT LEADER           110000        102                                      
                                                                                
       102 VIJAY      BTECH   1234567892 vijay@digisol.com                      
PROJECT MANAGER          120000        110                                      
                                                                                

   EMPCODE NAME       QUALIFI      PHONE EMAIL                                  
---------- ---------- ------- ---------- --------------------                   
DESIGNATION              SALARY REPORTS_TO                                      
-------------------- ---------- ----------                                      
       108 AJAY       BTECH   1234567893 ajay@digisol.com                       
TECHNICAL HEAD           130000        102                                      
                                                                                
       110 BHASKAR    MTECH   1234567894 bhaskar@digisol.com                    
PROJECT DIRECTOR         140000        106                                      
                                                                                
       106 RAJ        MSC     1234567895 raj@digisol.com                        
PROJECT LEADER           150000        110                                      
                                                                                

   EMPCODE NAME       QUALIFI      PHONE EMAIL                                  
---------- ---------- ------- ---------- --------------------                   
DESIGNATION              SALARY REPORTS_TO                                      
-------------------- ---------- ----------                                      
       105 MANISH     MCA     1234567896 manish@digisol.com                     
DEVELOPER                160000        106                                      
                                                                                
       111 RAJ        BTECH   1236547895 nikhith@digisol.com                    
TECHNICAL HEAD           130000                                                 
                                                                                

8 rows selected.

SQL> select * from skill;

SKI SKILLNAME                                                                   
--- --------------------                                                        
S1  Full Stack                                                                  
S2  Python                                                                      
S3  Java                                                                        
S4  C++                                                                         
S6  Oracle                                                                      
S7  Android                                                                     
S8  AZURE                                                                       
S9  DOT NET                                                                     
S10 IOS                                                                         

9 rows selected.

SQL> insert into client values('C1','ABC','+48-87489389','aaa@abc.com');
insert into client values('C1','ABC','+48-87489389','aaa@abc.com')
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.VALID_EMAIL) violated 


SQL> alter table client drop constraint VALID_EMAIL;

Table altered.

SQL> ALTER TABLE CLIENT
  2  ADD (EMAIL varchar(20) CONSTRAINT VALID_EMAIL CHECK(email like '%@%.___'));
ADD (EMAIL varchar(20) CONSTRAINT VALID_EMAIL CHECK(email like '%@%.___'))
     *
ERROR at line 2:
ORA-01430: column being added already exists in table 


SQL> ALTER TABLE CLIENT
  2  ADD (CONSTRAINT VALID_EMAIL CHECK(email like '%@%.___'));

Table altered.

SQL> insert into client values('C1','ABC','+48-87489389','aaa@abc.com');

1 row created.

SQL> select * from client;

CLI NAME       PHONE          EMAIL                                             
--- ---------- -------------- --------------------                              
C1  ABC        +48-87489389   aaa@abc.com                                       

SQL> insert into client values('C2','LTS','+91-78389397','bbb@lts.com');

1 row created.

SQL> insert into client values('C3','RK','+44-67838934','ccc@rk.com');

1 row created.

SQL> insert into client values('C4','MMA','+31-77839093','ddd@mma.com');

1 row created.

SQL> insert into client values('C5','AKS','+81-66822903','eee@aks.com');

1 row created.

SQL> insert into client values('C6','GKS','+78-75628982','fff@gks.com');
insert into client values('C6','GKS','+78-75628982','fff@gks.com')
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.PHONE_FORMAT) violated 


SQL> insert into client values('C7','B&B','+91-64839839','ggg@bb.com');
Enter value for b: insert into client values('C8','ABT','+97-67554667','hhh@tt.com');
old   1: insert into client values('C7','B&B','+91-64839839','ggg@bb.com')
new   1: insert into client values('C7','Binsert into client values('C8','ABT','+97-67554667','hhh@tt.com');','+91-64839839','ggg@bb.com')
insert into client values('C7','Binsert into client values('C8','ABT','+97-67554667','hhh@tt.com');','+91-64839839','ggg@bb.com')
                                                            *
ERROR at line 1:
ORA-00917: missing comma 


SQL> insert into client values('C9','XYZ','+48-25368596','xyz.ab.com');
insert into client values('C9','XYZ','+48-25368596','xyz.ab.com')
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.VALID_EMAIL) violated 


SQL> insert into client values('C5','AKS','+81-66822903','eee@aks.com');
insert into client values('C5','AKS','+81-66822903','eee@aks.com')
*
ERROR at line 1:
ORA-00001: unique constraint (DSE108.PK_CLIENTID) violated 


SQL> select * from client;

CLI NAME       PHONE          EMAIL                                             
--- ---------- -------------- --------------------                              
C1  ABC        +48-87489389   aaa@abc.com                                       
C2  LTS        +91-78389397   bbb@lts.com                                       
C3  RK         +44-67838934   ccc@rk.com                                        
C4  MMA        +31-77839093   ddd@mma.com                                       
C5  AKS        +81-66822903   eee@aks.com                                       

SQL> insert into client values('C7','B&B','+91-64839839','ggg@bb.com');
Enter value for b: 2
old   1: insert into client values('C7','B&B','+91-64839839','ggg@bb.com')
new   1: insert into client values('C7','B2','+91-64839839','ggg@bb.com')

1 row created.

SQL> insert into client values('C8','ABT','+97-67554667','hhh@tt.com');
insert into client values('C8','ABT','+97-67554667','hhh@tt.com')
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.PHONE_FORMAT) violated 


SQL> insert into client values('C9','XYZ','+48-25368596','xyz.ab.com');
insert into client values('C9','XYZ','+48-25368596','xyz.ab.com')
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.VALID_EMAIL) violated 


SQL> select * from client;

CLI NAME       PHONE          EMAIL                                             
--- ---------- -------------- --------------------                              
C1  ABC        +48-87489389   aaa@abc.com                                       
C2  LTS        +91-78389397   bbb@lts.com                                       
C3  RK         +44-67838934   ccc@rk.com                                        
C4  MMA        +31-77839093   ddd@mma.com                                       
C5  AKS        +81-66822903   eee@aks.com                                       
C7  B2         +91-64839839   ggg@bb.com                                        

6 rows selected.

SQL> insert into emp_skill values(100,'S1',15);

1 row created.

SQL> insert into emp_skill values(100,'S3',10);

1 row created.

SQL> insert into emp_skill values(101,'S1',6);

1 row created.

SQL> insert into emp_skill values(101,'S2',10);

1 row created.

SQL> insert into emp_skill values(102,'S4',18);

1 row created.

SQL> insert into emp_skill values(110,'S1',14);

1 row created.

SQL> insert into emp_skill values(110,'S6',20);

1 row created.

SQL> insert into emp_skill values(106,'S2',10);

1 row created.

SQL> insert into emp_skill values(106,'S6',12);

1 row created.

SQL> insert into emp_skill values(106,'S8',10);

1 row created.

SQL> insert into emp_skill values(108,'S9',5);

1 row created.

SQL> insert into emp_skill values(108,'S6',18);

1 row created.

SQL> insert into emp_skill values(105,'S7',12);

1 row created.

SQL> insert into emp_skill values(105,'S10',11);

1 row created.

SQL> insert into emp_skill values(101,'S2',7);
insert into emp_skill values(101,'S2',7)
*
ERROR at line 1:
ORA-00001: unique constraint (DSE108.PK_EMPNO_SKILLID) violated 


SQL> insert into emp_skill values(100,'S1',15);
insert into emp_skill values(100,'S1',15)
*
ERROR at line 1:
ORA-00001: unique constraint (DSE108.PK_EMPNO_SKILLID) violated 


SQL> insert into work_exp(100,'P1',20,'C1','A');
insert into work_exp(100,'P1',20,'C1','A')
                     *
ERROR at line 1:
ORA-00928: missing SELECT keyword 


SQL> desc client;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 CLIENTID                                  NOT NULL CHAR(3)
 NAME                                               VARCHAR2(10)
 PHONE                                              CHAR(14)
 EMAIL                                              VARCHAR2(20)

SQL> insert into prj_details values('P1','SPYDER',10-01-2020,11-10-2022,12-10-2022,102,2000000,1990000);
insert into prj_details values('P1','SPYDER',10-01-2020,11-10-2022,12-10-2022,102,2000000,1990000)
                                                  *
ERROR at line 1:
ORA-00932: inconsistent datatypes: expected DATE got NUMBER 


SQL> insert into prj_details values('P1','SPYDER','10-01-2020','11-10-2022','12-10-2022',102,2000000,1990000);
insert into prj_details values('P1','SPYDER','10-01-2020','11-10-2022','12-10-2022',102,2000000,1990000)
                                             *
ERROR at line 1:
ORA-01843: not a valid month 


SQL> insert into prj_details values('P1','SPYDER','10/01/2020','11/10/2022','12/10/2022',102,2000000,1990000);
insert into prj_details values('P1','SPYDER','10/01/2020','11/10/2022','12/10/2022',102,2000000,1990000)
                                             *
ERROR at line 1:
ORA-01843: not a valid month 


SQL> insert into prj_details values('P1','SPYDER','10/Jan/2020','11/Oct/2022','12/Oct/2022',102,2000000,1990000);

1 row created.

SQL> insert into prj_details values('P2','APOLLO',01-Jan-2019,10-Jul-2021,11-Jul-2021,108,3000000,3600000);
insert into prj_details values('P2','APOLLO',01-Jan-2019,10-Jul-2021,11-Jul-2021,108,3000000,3600000)
                                                                        *
ERROR at line 1:
ORA-00984: column not allowed here 


SQL> insert into prj_details values('P2','APOLLO',01/Jan/2019,10/Jul/2021,30/Jul/2021,108,3000000,3600000);insert into prj_details values('P2','APOLLO',01/Jan/2019,10/Jul/2021,30/Jul/2021,108,3000000,3600000);
insert into prj_details values('P2','APOLLO',01/Jan/2019,10/Jul/2021,30/Jul/2021,108,3000000,3600000);insert into prj_details values('P2','APOLLO',01/Jan/2019,10/Jul/2021,30/Jul/2021,108,3000000,3600000)
                                                                                                     *
ERROR at line 1:
ORA-00933: SQL command not properly ended 


SQL> insert into prj_details values('P2','APOLLO',01/Jan/2019,10/Jul/2021,30/Jul/2021,108,3000000,3600000);
insert into prj_details values('P2','APOLLO',01/Jan/2019,10/Jul/2021,30/Jul/2021,108,3000000,3600000)
                                                                        *
ERROR at line 1:
ORA-00984: column not allowed here 


SQL> insert into prj_details values('P2','APOLLO','01/Jan/2019','10/Jul/2021','30/Jul/2021',108,3000000,3600000);

1 row created.

SQL> select * from prj_details;

PRJ PRJ_NAME   START_DAT END_DATE  ACTUAL_EN LEAD_BY_EMPCODE BUDGET_ALLOCATED   
--- ---------- --------- --------- --------- --------------- ----------------   
ACTUAL_BUDGET                                                                   
-------------                                                                   
P1  SPYDER     10-JAN-20 11-OCT-22 12-OCT-22             102          2000000   
      1990000                                                                   
                                                                                
P2  APOLLO     01-JAN-19 10-JUL-21 30-JUL-21             108          3000000   
      3600000                                                                   
                                                                                

SQL> insert into prj_details values('P3','UNICORN','03/Nov/2021','10/Oct/2023','10/Oct/2023',106,7500000,8000000);

1 row created.

SQL> insert into prj_details values('P4','ZEUS','28/Feb/2020','09/Jun/2021','10/Jan/2022',110,5500000,5000000);

1 row created.

SQL> insert into prj_details values('P5','JUPITER','07/Aug/2018','04/Feb/2020','01/Nov/2020',110,9000000,9000000);

1 row created.

SQL> insert into prj_details values('P6','MARS','21/Feb/2022','07/Aug/2020','09/Dec/2020',135,8000000,9000000);
insert into prj_details values('P6','MARS','21/Feb/2022','07/Aug/2020','09/Dec/2020',135,8000000,9000000)
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.END_DATE_GREATER_START_DATE) violated 


SQL> insert into prj_details values(Null,'XXX','21/Feb/2019','08/Aug/2020','10/Dec/2020',138,8000000,9000000);
insert into prj_details values(Null,'XXX','21/Feb/2019','08/Aug/2020','10/Dec/2020',138,8000000,9000000)
                               *
ERROR at line 1:
ORA-01400: cannot insert NULL into ("DSE108"."PRJ_DETAILS"."PRJID") 


SQL> insert into prj_details values('P7','SATURN','21/Feb/2020','08/Aug/2021','10/Dec/2021',123,8500000,9400000);
insert into prj_details values('P7','SATURN','21/Feb/2020','08/Aug/2021','10/Dec/2021',123,8500000,9400000)
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.FK_LEAD_EMP) violated - parent key not 
found 


SQL> insert into work_exp(100,'P1',20,'C1','A');
insert into work_exp(100,'P1',20,'C1','A')
                     *
ERROR at line 1:
ORA-00928: missing SELECT keyword 


SQL> insert into work_exp values(100,'P1',20,'C1','A');
insert into work_exp values(100,'P1',20,'C1','A')
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.SYS_C0021115) violated - parent key not 
found 


SQL> insert into work_exp values(100,'P3',15,'C3','A');
insert into work_exp values(100,'P3',15,'C3','A')
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.SYS_C0021115) violated - parent key not 
found 


SQL> insert into medical_policy values(100,'MED001',10000,10-12-2020);
insert into medical_policy values(100,'MED001',10000,10-12-2020)
                                                          *
ERROR at line 1:
ORA-00932: inconsistent datatypes: expected DATE got NUMBER 


SQL> insert into work_exp values(100,'P1',20,'C1','A');
insert into work_exp values(100,'P1',20,'C1','A')
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.SYS_C0021115) violated - parent key not 
found 


SQL> insert into work_exp values(101,'P1',16,'C1','A');
insert into work_exp values(101,'P1',16,'C1','A')
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.SYS_C0021115) violated - parent key not 
found 


SQL> select * client;
select * client
         *
ERROR at line 1:
ORA-00923: FROM keyword not found where expected 


SQL> select * from client;

CLI NAME       PHONE          EMAIL                                             
--- ---------- -------------- --------------------                              
C1  ABC        +48-87489389   aaa@abc.com                                       
C2  LTS        +91-78389397   bbb@lts.com                                       
C3  RK         +44-67838934   ccc@rk.com                                        
C4  MMA        +31-77839093   ddd@mma.com                                       
C5  AKS        +81-66822903   eee@aks.com                                       
C7  B2         +91-64839839   ggg@bb.com                                        

6 rows selected.

SQL> select * from prj_details;

PRJ PRJ_NAME   START_DAT END_DATE  ACTUAL_EN LEAD_BY_EMPCODE BUDGET_ALLOCATED   
--- ---------- --------- --------- --------- --------------- ----------------   
ACTUAL_BUDGET                                                                   
-------------                                                                   
P1  SPYDER     10-JAN-20 11-OCT-22 12-OCT-22             102          2000000   
      1990000                                                                   
                                                                                
P2  APOLLO     01-JAN-19 10-JUL-21 30-JUL-21             108          3000000   
      3600000                                                                   
                                                                                
P3  UNICORN    03-NOV-21 10-OCT-23 10-OCT-23             106          7500000   
      8000000                                                                   
                                                                                

PRJ PRJ_NAME   START_DAT END_DATE  ACTUAL_EN LEAD_BY_EMPCODE BUDGET_ALLOCATED   
--- ---------- --------- --------- --------- --------------- ----------------   
ACTUAL_BUDGET                                                                   
-------------                                                                   
P4  ZEUS       28-FEB-20 09-JUN-21 10-JAN-22             110          5500000   
      5000000                                                                   
                                                                                
P5  JUPITER    07-AUG-18 04-FEB-20 01-NOV-20             110          9000000   
      9000000                                                                   
                                                                                

SQL> select * from emp;

   EMPCODE NAME       QUALIFI      PHONE EMAIL                                  
---------- ---------- ------- ---------- --------------------                   
DESIGNATION              SALARY REPORTS_TO                                      
-------------------- ---------- ----------                                      
       100 RAJESH     BTECH   1234567890 rajesh@digisol.com                     
DEVELOPER                100000        101                                      
                                                                                
       101 RAVI       MTECH   1234567891 ravi@digisol.com                       
PROJECT LEADER           110000        102                                      
                                                                                
       102 VIJAY      BTECH   1234567892 vijay@digisol.com                      
PROJECT MANAGER          120000        110                                      
                                                                                

   EMPCODE NAME       QUALIFI      PHONE EMAIL                                  
---------- ---------- ------- ---------- --------------------                   
DESIGNATION              SALARY REPORTS_TO                                      
-------------------- ---------- ----------                                      
       108 AJAY       BTECH   1234567893 ajay@digisol.com                       
TECHNICAL HEAD           130000        102                                      
                                                                                
       110 BHASKAR    MTECH   1234567894 bhaskar@digisol.com                    
PROJECT DIRECTOR         140000        106                                      
                                                                                
       106 RAJ        MSC     1234567895 raj@digisol.com                        
PROJECT LEADER           150000        110                                      
                                                                                

   EMPCODE NAME       QUALIFI      PHONE EMAIL                                  
---------- ---------- ------- ---------- --------------------                   
DESIGNATION              SALARY REPORTS_TO                                      
-------------------- ---------- ----------                                      
       105 MANISH     MCA     1234567896 manish@digisol.com                     
DEVELOPER                160000        106                                      
                                                                                
       111 RAJ        BTECH   1236547895 nikhith@digisol.com                    
TECHNICAL HEAD           130000                                                 
                                                                                

8 rows selected.

SQL> desc work_exp;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 EMPCODE                                   NOT NULL NUMBER(3)
 PRJID                                     NOT NULL CHAR(2)
 WORK_EXPERIENCE                           NOT NULL NUMBER(2)
 CLIENTID                                           CHAR(3)
 RATING                                             CHAR(1)

SQL> desc client;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 CLIENTID                                  NOT NULL CHAR(3)
 NAME                                               VARCHAR2(10)
 PHONE                                              CHAR(14)
 EMAIL                                              VARCHAR2(20)

SQL> desc prj_details;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 PRJID                                     NOT NULL CHAR(3)
 PRJ_NAME                                           VARCHAR2(10)
 START_DATE                                         DATE
 END_DATE                                           DATE
 ACTUAL_END_DATE                                    DATE
 LEAD_BY_EMPCODE                                    NUMBER(3)
 BUDGET_ALLOCATED                                   NUMBER(10,1)
 ACTUAL_BUDGET                                      NUMBER(10,1)

SQL> desc emp;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 EMPCODE                                   NOT NULL NUMBER(3)
 NAME                                               VARCHAR2(10)
 QUALIFICATION                                      VARCHAR2(7)
 PHONE                                              NUMBER(10)
 EMAIL                                              VARCHAR2(20)
 DESIGNATION                                        VARCHAR2(20)
 SALARY                                             NUMBER(7)
 REPORTS_TO                                         NUMBER(3)

SQL> alter table work_exp drop column prjid;
alter table work_exp drop column prjid
                                 *
ERROR at line 1:
ORA-12991: column is referenced in a multi-column constraint 


SQL> drop table work_exp;

Table dropped.

SQL> create table work_exp(
  2  empcode number(3) references emp,
  3  prjid char(3) references prj_details,
  4  work_experience number(2) check(work_experience >= 0) not null,
  5  clientid references client on delete set null,
  6  rating char(1) check(rating in ('A','B','C')),
  7  primary key(empcode,prjid));

Table created.

SQL> desc work_exp;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 EMPCODE                                   NOT NULL NUMBER(3)
 PRJID                                     NOT NULL CHAR(3)
 WORK_EXPERIENCE                           NOT NULL NUMBER(2)
 CLIENTID                                           CHAR(3)
 RATING                                             CHAR(1)

SQL> insert into work_exp values(100,'P1',20,'C1','A');

1 row created.

SQL> insert into work_exp values(100,'P3',15,'C3','A');

1 row created.

SQL> insert into work_exp values(101,'P1',16,'C1','A');

1 row created.

SQL> insert into work_exp values(102,'P2',18,'C2','B');

1 row created.

SQL> insert into work_exp values(102,'P1',18,'C1','A');

1 row created.

SQL> insert into work_exp values(108,'P2',12,'C2','C');

1 row created.

SQL> insert into work_exp values(106,'P3',20,'C3','C');

1 row created.

SQL> insert into work_exp values(106,'P4',10,'C4','C');

1 row created.

SQL> insert into work_exp values(105,'P2',19,'C2','B');

1 row created.

SQL> insert into work_exp values(110,'P4',12,'C4','B');

1 row created.

SQL> insert into work_exp values(110,'P5',16,'C8','A');
insert into work_exp values(110,'P5',16,'C8','A')
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.SYS_C0021397) violated - parent key not 
found 


SQL> insert into work_exp values(105,'P5',5,'C5','D');
insert into work_exp values(105,'P5',5,'C5','D')
*
ERROR at line 1:
ORA-02290: check constraint (DSE108.SYS_C0021393) violated 


SQL> insert into work_exp values(111,'P5',5,'C5','C');

1 row created.

SQL> insert into medical_policy values(100,'MED001',10000,'10/Dec/2020');
insert into medical_policy values(100,'MED001',10000,'10/Dec/2020')
                                      *
ERROR at line 1:
ORA-12899: value too large for column "DSE108"."MEDICAL_POLICY"."POLICYNO" 
(actual: 6, maximum: 5) 


SQL> insert into medical_policy values(100,'MED01',10000,'10/Dec/2020');
insert into medical_policy values(100,'MED01',10000,'10/Dec/2020')
                                              *
ERROR at line 1:
ORA-01438: value larger than specified precision allowed for this column 


SQL> drop table medical_policy;

Table dropped.

SQL> create table medical_policy(
  2  empno references emp,
  3  policyno varchar(7) constraint C_PNo check(policyno like 'MED%'),
  4  premium number(7) constraint C_P check(premium >0),
  5  policydate date,
  6  primary key(empno,policyno));

Table created.

SQL> alter table medical_policy
  2  drop primary key;

Table altered.

SQL> 
SQL> alter table medical_policy
  2  add constraint PK_MP
  3  primary key(empno,policyno,policydate);

Table altered.

SQL> alter table medical_policy
  2  drop constraint C_p;

Table altered.

SQL> 
SQL> alter table medical_policy
  2  add constraint C_P
  3  check(premium > 1000);

Table altered.

SQL> insert into medical_policy values(100,'MED01',10000,'10/Dec/2020');

1 row created.

SQL> insert into medical_policy values(101,'MED03',12000,'15/Dec/2020');

1 row created.

SQL> insert into medical_policy values(100,'MED01',10000,'10/Jan/2021');

1 row created.

SQL> insert into medical_policy values(101,'MED03',12000,'15/Oct/2021');

1 row created.

SQL> insert into medical_policy values(103,'MED04',9000,'21/Jan/2021');
insert into medical_policy values(103,'MED04',9000,'21/Jan/2021')
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.SYS_C0021417) violated - parent key not 
found 


SQL> insert into family_dependents values(100,'AJITH','SON',12);

1 row created.

SQL> insert into family_dependents values(100,'PRITHVI','DAUGHTER',9);

1 row created.

SQL> insert into family_dependents values(101,'AARYA','DAUGHTER',17);

1 row created.

SQL> insert into family_dependents values(101,'AKANKSH','SON',11);

1 row created.

SQL> insert into family_dependents values(101,'ANITHA','SPOUSE',43);

1 row created.

SQL> insert into pay_check values(100,'01/Dec/2020',2000,123,456,789,2500,5000);

1 row created.

SQL> insert into pay_check values(101,'01/Dec/2020',3000,2400,5000,2300,5000,7000);

1 row created.

SQL> insert into pay_check values(102,'01/Dec/2020',3000,2500,5400,2400,3600,7000);

1 row created.

SQL> insert into pay_check values(100,'01/Jan/2021',3000,3000,4500,5000,450,4000);

1 row created.

SQL> insert into pay_check values(101,'01/Jan/2021',5000,3500,4000,5500,2100,4000);

1 row created.

SQL> insert into pay_check values(102,'01/Jan/2021',5000,3600,4600,5800,NULL,9000);

1 row created.

SQL> insert into pay_check values(103,'02/Jan/2021',7000,2500,1400,3600,900,3000);
insert into pay_check values(103,'02/Jan/2021',7000,2500,1400,3600,900,3000)
*
ERROR at line 1:
ORA-02291: integrity constraint (DSE108.SYS_C0020885) violated - parent key not 
found 


SQL> spool off;
