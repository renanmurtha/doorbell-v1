
# DoorBell-v1 (ESP-01 S)

Aplicação em C/C++ voltada para IOT.
- [README-ENG](README-ENG.md)
#

## Tipo de uso:

- Botão de emergência;
- Campainha;
- Outros

#
## Material

- Dispositivo: ESP-01S
- Bateria: 902030 Li Ion - 550mah - 3.7v
- Controlador de carga: TP4056 (18650)
- Carregador de celular 1A (Amperagem maior pode danificar a bateria e/ou contrlador de carga)
- Botão ( Chave Push Button ); usei esses de campanhia
<br/>

#

## Ajuste no projeto

- Renomear o arquivo define_exemplo.h para define.h e renomear as constantes com as credenciais do seu servidor mqtt, e do wifi.

<br/>
<br/>

# Funcionamento:

Dispositivo fica em "sono profundo" até o botão de reset ser precionado. O dispositivo "desperta", manda mensagem para o servidor mqtt e volta ao estado de "sono profundo".

No meu uso, adicionei uma bateria 902030 Li Ion - 550mah - 3.7v.

Para carrgar a bateria, adicionei no projto o controlador de carga TP4056 (18650); * Usar carregador de 1A para não danificar nem o carregador e nem a bateria.

#

## Padrão de Mensagem

Optei em usar o padrão Json para enviar as mensagens para o servidor mqtt embutido no Node-Red. 
<br/>
Usando Json, consigo fazer varias ações usando a string json.
 
 ### Exemplos 
 
 * Salvar o evento no mongo DB
 * Enviar mensagem para o telegram
 * Evniar mensagem para whatszap 

 Com os dados da mensagem em json, pode se fazer tratamento por dispositivo, e disparar ações para destinatarios diferentes de acordo com a identificação do dispositivo.

 # 

<br/>

  - Exemplo JSON
  
  <br/>

  ![Exemplo JSON](https://github.com/renanmurtha/doorbell-v1/blob/main/img/json.png?raw=true "Exemplo JSON")
  
  - Node-Red (NODES)

  <br/>

  ![Nodes que uso (Node-Red)](https://github.com/renanmurtha/doorbell-v1/blob/main/img/node-red.png?raw=true "Exemplo JSON")

   - Sketch

  <br/>

  ![Sketch](https://github.com/renanmurtha/doorbell-v1/blob/main/img/Sketch.png?raw=true "Sketch")