/** The what and the why of concurrency
 */

/*

    Concurrency:
        It is the ability to allow us to do two or more things at any given time and there is some ordering to these events.

        The fact of two or more events or circuntances happening or existing at the same time

    NOTE: concurrency is different than parallelism.


    - This is somewhat reflects how we erite software

    Typically we have one main, sequential thread of execution.
    One CPU core execites code sequentially


        --------------   execute    --------------   execute    --------------   execute    --------------   execute  
       | INSTRUCTION  | -------->  | INSTRUCTION  | -------->  | INSTRUCTION  | -------->  | INSTRUCTION  | --------> .....   
        --------------              --------------              --------------              --------------           
       
        
    We can abstract our visalization, and just show the call stack (One function calling the other, with the indentation indicating
    the call stack)


        -------
       | main  |  
        -------
            -------
           | foo() |  
            -------
            -------
           | bar() |  
            -------
                -------
               | bar() |  
                -------

    But waht if we could have a second path in our code executing


        main exeution path:                More work being
        -------                            completed
       | main  |                           concurrently on a
        -------                            second path
            -------                        -------   
           | foo() |                      | foo() |  
            -------                        -------
            -------                        -------
           | bar() |                      | bar() |  
            -------                        -------
                -------                         -------
               | bar() |                       | bar() |  
                -------                         -------


    Performance is the concurrency of computing:
    -------------------------------------------

        Parallelism: 
            Everything happends at once, instantaneosly.

            For ex: Two queues, Two caffe machines

                                              ---------
            ° ° ° ° ° ° ° ° ° ° ° °          |  Coffe  |
            | | | | | | | | | | | |   --->   | Machine |
                                              ---------
               
                                              ---------
            ° ° ° ° ° ° ° ° ° ° ° °          |  Coffe  |
            | | | | | | | | | | | |   --->   | Machine |
                                              ---------


        Concurrency: 
            Multiple things can happen at once, the order matters, and sometimes tasks have to wait on shared resources.
            There might be som syncronization points that we have to keep in mind

            For ex:Two queues, One caffe machines

                                              
            ° ° ° ° ° ° ° ° ° ° ° °          
            | | | | | | | | | | | |   ---->    ---------
                                              |  Coffe  |
                                              | Machine |
                                               ---------
            ° ° ° ° ° ° ° ° ° ° ° °   ---->      
            | | | | | | | | | | | |   



        Concurrency and parallelism (implemented correctly) should yield better performance.
*/