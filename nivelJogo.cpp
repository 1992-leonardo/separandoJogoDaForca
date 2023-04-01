    #include <iostream>
    #include <cstdlib>
    #include <ctime>

    extern int numero_de_tentativas;

    void nivelJogo(){
    
    std::cout << "Escolha o seu nível de dificuldade:" << std::endl;
    std::cout << "Fácil (F), Médio (M) ou Difícil (D)" << std::endl;

    char dificuldade;
    std::cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F' || dificuldade == 'f'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M' || dificuldade == 'm'){
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }  
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1;tentativas <= numero_de_tentativas;tentativas++)
    {
        int chute;
        std::cout << "Tentativa " << tentativas << std::endl;
        std::cout << "Qual seu chute? ";
        std::cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        std::cout << "O valor do seu chute é: " << chute << std::endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            std::cout << "Parabéns! Você acertou o número secreto!" << std::endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            std::cout << "Seu chute foi maior que o número secreto!" << std::endl;
        }
        else
        {
            std::cout << "Seu chute foi menor que o número secreto!" << std::endl;
        }
    }

    std::cout << "Fim de jogo!" << std::endl;
    if(nao_acertou){
        std::cout << "Você perdeu! Tente novamente!" << std::endl;
    }
    else{
        std::cout << "Você acertou o número secreto em " << tentativas << " tentativas" << std::endl;
        std::cout.precision(2);
        std::cout.fixed;
        std::cout << "Sua pontuação foi de " << pontos << " pontos." << std::endl;
    }     

    }