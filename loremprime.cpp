#include <iostream>
#include <string>

int main(){
    std::string paragraph = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque rutrum nunc tortor, sed facilisis risus tristique tincidunt. Pellentesque imperdiet nec massa quis viverra. Nullam laoreet eu neque vitae hendrerit. Phasellus euismod consequat lacus, quis aliquet nunc rhoncus eu. Nulla ut lacus et risus aliquam vestibulum. Nullam lorem sapien, pulvinar et accumsan vel, placerat a tortor. Curabitur quis tellus viverra, sagittis turpis et, tempus lacus. Quisque feugiat lobortis turpis ac ultricies. Aenean nec lacus in nunc bibendum ornare vitae at nisi. Nulla porttitor felis ante. Aenean non sodales urna. Suspendisse tempus massa non dolor lacinia finibus. Fusce accumsan quam at magna dapibus luctus. Nunc ut cursus lacus. Nulla in molestie lectus. Cras at egestas libero. Phasellus vel iaculis magna, id ultrices metus. Nulla vestibulum nisl ut porta posuere. Nulla et tincidunt ligula, vitae finibus leo. Curabitur gravida lacinia dolor semper consectetur. Etiam feugiat sapien a placerat convallis. Proin vehicula ex vitae purus convallis, hendrerit faucibus enim semper. Vestibulum eu rhoncus quam, vitae sodales sem. Fusce faucibus varius euismod. Fusce volutpat est nec pellentesque laoreet.";

    for (int i = 2; i < 200; i++){
        bool prime = true;
        for (int j =2; j*j<=i; j++){
            if (i % j == 0){
                prime = false;
                break;
            }
        }
        if (prime){
            for (int j = 0; j < i; j++){
                std::cout << paragraph[j];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}