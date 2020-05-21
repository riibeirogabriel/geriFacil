# geriFacil: Um software para revenda de produtos
Software desenvolvido para um revendendor que trabalha com venda de produtos para lojas e comércios, o revendendor gastava muito tempo coletando semanalmente os produtos que cada comerciante necessitava, tendo que, após coletar via anotações os produtos que cada lojista necessitava, elaborar uma planilha com o somatório de todos os produtos que precisava comprar em cada revenda.\
Com o geriFacil, o revendendor cadastra todos os produtos que revende e todos os seus clientes, colocando na tabela de cada cliente o tipo e a quantidade de cada produto, com isso, o software automatiza o processo de elaboração da planilha final com o somatório de todos os produtos que o revenendor deve comprar a cada revenda, economizando horas de trabalho manual, o geriFacil ainda possui opção de impressão da planilha de cada cliente ( serve como nota fiscal, devidamente assinada pelo revenendor e o comerciante), e também impressão da planilha final de cada revenda, há também a porcentagem de lucro sobre cada comerciante e o lucro total de cada revenda.

# Como executar
Para executar o geriFacil, é preciso ter [QT Creator](https://www.qt.io/download) instalado em sua máquina, no momento da instalação do QT Creator, na janela "Select Components", é necesário instalar o minGW contido na seção "Developer and Designer Tools", e de alguma seção do Qt 5.\
Depois de instalado o QT Creator, abra um projeto e selecione o arquivo GereFacil.pro, localizado dentro da pasta sources, e pronto, o QT Creator irá carregar o software e o iniciará.

# Especificação de requisitos ( Elaboração do software)
<div>

<span class="c12 c39"></span>

<span class="c39 c12"></span>

<span class="c31 c23 c12">Software para gestão de vendas</span>

<span class="c31 c23 c12">GeriFácil</span>

<span class="c39 c12"></span>

<span class="c5"></span>

</div>

<span class="c1"></span>

<span class="c1"></span>

<span class="c1"></span>

<span style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 188.50px; height: 188.50px;">![](images/image3.png)</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c1">GeriFácil - Software para gestão de vendas</span>

<span class="c1">Especificação de Requisitos</span>

<span class="c1"></span>

<span class="c23 c12 c55">Versão <1.0></span>

<span class="c5"></span>

<span class="c26"> </span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

* * *

<span class="c5"></span>

<span class="c5"></span>

* * *

<span class="c1">Índice</span>

<span class="c22 c12"></span>

<span class="c12">1.</span><span class="c29 c12">        </span><span class="c12">Objetivo        </span>

<span class="c12">2.</span><span class="c29 c12">        </span><span class="c12">Descrição do Produto                                                                </span><span>           </span>

<span>        </span><span class="c12">2.1</span><span class="c29"></span> <span class="c12">Escopo do Produto        </span>

<span>                 2.1.1   O que é?                                                                                                                                  </span>

<span>        </span><span class="c12">2.1.</span><span>2</span><span class="c29 c12">        </span><span class="c12">Nome do produto e de seus componentes principais        </span>

<span>        </span><span class="c12">2.1.</span><span>3</span><span class="c29 c12">        </span><span class="c12">Missão do produto        </span>

<span>        </span><span class="c12">2.1</span><span>.4</span><span class="c29 c12">        </span><span class="c5">Escopo</span>

<span>        2.1.5\.  Escopo negativo/Limites do Produto</span><span class="c12">        </span>

<span>        </span><span class="c12">2.1.</span><span>6</span><span class="c29 c12">        </span><span class="c12">Benefícios do produto        </span>

<span></span> <span class="c12">2.2</span><span class="c29">        </span><span class="c29 c12"> </span><span class="c12">Serviço oferecidos pelo produto                                                                   </span><span>           </span>

<span>        </span><span class="c12">2.2.1</span><span class="c12 c29">        </span><span class="c12">Diagrama de contexto        </span>

<span>        </span><span class="c12">2.2.2</span><span class="c29 c12">        </span><span class="c12">Descri</span><span>ç</span><span class="c12">ão dos Servi</span><span>ç</span><span class="c12">os        </span>

<span>        </span><span class="c12">2.2.3</span><span class="c29 c12">        </span><span class="c12">Generaliza</span><span>ç</span><span class="c12">ão dos Atores        </span>

<span>        </span><span class="c12">2.2.4</span><span class="c29 c12">        </span><span class="c12">Descri</span><span>ç</span><span class="c12">ão dos Atores        </span>

<span class="c12">3.</span><span class="c29 c12">        </span><span class="c5">Histórias de Usuário</span>

<span class="c5">4.        Backlog</span>

<span>4.1 Serviço de administração de clientes (CRUD)                                                        4.2        Serviço de impressão                                                                                4.3</span> <span class="c3">Serviço de Administração de produtos(CRUD</span><span class="c5">        )                                                4.4 Serviço de estatística                                                                                4.5         Serviço de relatório</span>

<span class="c5">5\.     Storyboard</span>



<span class="c5">6\.     Cronograma</span>

<span>        6.1 data das sprints</span>

<span>7</span><span class="c12">.</span><span class="c29 c12">        </span><span class="c5">Requisitos Não Funcionais</span>

<span>         7.1</span><span class="c29">         </span><span class="c5">Usabilidade</span>

<span class="c5">         7.2        Confiabilidade</span>

<span>          7.3        Portabilidade</span>

<span class="c12">                </span>

* * *

<span class="c1">Especificação de Requisitos  </span>

<span class="c26"></span>

# <span class="c31 c23 c12"> 1. Objetivo</span>

<span class="c5">Este documento tem objetivo de especificar os requisitos do GeriFácil, software de gestão de vendas.</span>

<span class="c5"></span>

# <span class="c31 c23 c12"> 2. Descrição do Produto</span>

## <span class="c24 c23 c12">2.1. Escopo do Produto</span>

### <span class="c12 c37">2.1.1. O que é?</span>

<span class="c5">        Sistema de gestão,armazenamento,elaboração de estatísticas e relatórios  de vendas realizadas em carga de produtos.</span>

### <span class="c37 c12">2.1.2. Nome do produto e de seus componentes principais</span>

<span class="c5">        O nome atribuído ao produto é GeriFácil. E será composto de um sistema desktop.</span>

### <span class="c37 c12">2.1.3. Missão do produto</span>

<span class="c5">        Gerir,criar estatísticas e relatórios sobre as vendas de uma carga,para otimizar o tempo gasto na tarefa.</span>

### <span>2.1.4. Escopo</span>

<span class="c5">        Possui autenticação para ter acesso ao Sistema</span>

<span class="c5">Possui uma tabela para cada cliente.</span>

<span class="c5">        Possuirá uma tabela com o registro de todos os produtos á venda.</span>

<span class="c5">        Possuirá uma tabela com os produtos que estão em estoque.</span>

<span class="c5">        À cada compra de produtos(carga), o sistema irá gerar uma tabela com a soma de produtos a serem comprados,podendo variar por região(cidade),mistura de regiões(cidades diferentes) ou o total das regiões(todas as cidades)</span>

<span class="c5">        O Sistema deverá armazenar um histórico de compras de cada cliente para análise</span>

<span class="c5">        O Sistema deverá auto-completar a inserção de produtos na tabela de um cliente.</span>

<span class="c5">        O Sistema deverá ter a opção de  imprimir qualquer tipo de tabela gerada.</span>

<span class="c5">         A cada carga realizada,as tabelas dos clientes deverão ser limpas para a próxima carga.</span>

<span class="c5">        O usuário terá autonomia para definir um preço de venda de um produto diferente para cada cliente,tendo com base,o valor de venda na tabela de produtos.</span>

<span class="c5">        O sistema poderá atualizar o valor de custo de um produto através de um arquivo .xls</span>

<span class="c5">        O sistema deverá dar o máximo de autonomia ao usuário,sendo o mais editável possível quanto ás informações apresentadas nas tabelas.</span>

<span class="c5">        </span>

### <span class="c37 c12">2.1.5. Escopo negativo/Limites do produto</span>

<span class="c5">Não haverá acesso via biometria.</span>

<span class="c5">Não haverá acesso por e-mail.</span>

<span class="c5">Não haverá forma automática de recuperação de senha.</span>

<span class="c5">Não haverá portabilidade das tabelas armazenadas no sistema.</span>

### <span class="c37 c12">2.1.6. Benefícios do produto</span>

<span class="c5">Com o GeriFácil,o usuário(a princípio Luciano) terá uma grande economia de tempo,pois até agora,toda a gestão das vendas de produtos está sendo feita á mão,tanto na coleta de dados(continuará assim) quanto na elaboração da tabela com os produtos a serem comprados em uma carga,esta tarefa consome horas,com o software,luciano terá grande economia de tempo na gestão do produto e ainda terá estatísticas quanto á seus clientes.</span>

<span class="c5"></span>

## <span class="c24 c23 c12">2.2. Serviço oferecidos pelo produto</span>

<span class="c5"></span>

### <span class="c37 c12">2.2.1. Diagrama de contexto</span>

<span class="c34"></span>

<span style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 397.00px; height: 521.00px;">![](images/image6.png)</span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c49">Figura 1 – Diagrama de Contexto do Sistema</span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c34"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

### <span class="c23 c12 c31">2.2.2. Descrição dos Serviços</span>

<span class="c5">        </span>

<span class="c5">        </span>

<a id="t.cdee1ceb99a162395f56bbf75960ffc09530c9a6"></a><a id="t.0"></a>

<table class="c54">

<tbody>

<tr class="c18">

<td class="c20 c47" colspan="1" rowspan="1">

<span class="c13 c48 c12">Número</span>

</td>

<td class="c20 c47" colspan="1" rowspan="1">

<span class="c13 c48 c12">Nome</span>

</td>

<td class="c20 c47" colspan="1" rowspan="1">

<span class="c13 c12 c48">Descrição</span>

</td>

</tr>

<tr class="c18">

<td class="c20" colspan="1" rowspan="1">

<span class="c5"></span>

<span class="c5"></span>

<span class="c5">1</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5"></span>

<span class="c5">Serviço de Administração de Clientes</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Cria,atualiza,remove e visualiza</span>

<span class="c5">dados de clientes,como a tabela de compras,ou registros do estabelecimento.</span>

</td>

</tr>

<tr class="c11">

<td class="c20" colspan="1" rowspan="1">

<span class="c5"></span>

<span class="c5"></span>

<span class="c5">2</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5"></span>

<span class="c5">Serviço de Impressão</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Imprime as tabelas e relatórios gerados no sistema</span>

</td>

</tr>

<tr class="c11">

<td class="c20" colspan="1" rowspan="1">

<span class="c5">3</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Serviço de Administração de Produtos</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Cria,atualiza, remove e visualiza produtos que o proprietário vende.</span>

</td>

</tr>

<tr class="c11">

<td class="c20" colspan="1" rowspan="1">

<span class="c5">4</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Serviço de Estatística</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Cria e mostra dados tratados de clientes específicos, ou de todos os clientes,também possui um histórico de compras por cliente.</span>

</td>

</tr>

<tr class="c11">

<td class="c20" colspan="1" rowspan="1">

<span class="c5">5</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Serviço de Relatório</span>

</td>

<td class="c20" colspan="1" rowspan="1">

<span class="c5">Gera um relatório da carga atual,com a soma por  produto que os clientes compraram.</span>

</td>

</tr>

</tbody>

</table>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c12 c15"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

### <span class="c23 c12 c31"> 2.2.3 Generalização dos Atores</span>

<span class="c15 c12"></span>

<span style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 62.00px; height: 121.00px;">![](images/image2.png)</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

<span class="c15 c12"></span>

### <span class="c23 c12 c31">2.2.4  Descrição dos Atores</span>

<span class="c13 c12"></span>

<span class="c23">Proprietário:</span> <span class="c5">Dono do software e do negócio de revendas,irá utilizar o software.</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

# <span>3. Histórias de Usuário</span><span class="c33"> </span>

<a id="t.3d42340b96984edd5f3d24e9a16da1644298e8de"></a><a id="t.1"></a>

<table class="c54">

<tbody>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c13 c12">Serviço</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c13 c12">Como</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c13 c12">Eu quero</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c13 c12">Para que</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c12 c13">Sprint</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">Administração de clientes</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">Adicionar um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Ele faça parte do sistema e dos relatórios</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">Administração de clientes</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Atualizar os dados de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">As informações cadastrais do clientes se mantenham atualizadas para uma eventual consulta</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de clientes</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Atualizar a tabela de um cliente da carga atual</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">não falte produtos na compra da carga</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7"></span>

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de clientes</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Remover um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">.Ele não esteja cadastrada no sistema.</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de clientes</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Visualizar cargas passadas de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">analisar o histórico de compra de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de clientes</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Visualizar os dados cadastrais de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">obter alguma informação necessário do cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de clientes</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Visualizar carga atual de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">analisar a carga atual do cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Impressão</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Imprimir o relatório da carga</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">consiga acompanhar os pedidos sem a presença de um computador</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">2</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Impressão</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Imprimir pedidos da carga atual de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">posso entregá-lo uma segunda via do pedido.</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">2</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Impressão</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Imprimir histórico de pedidos de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Poder acompanhar algum ocorrido,ou analisar as compras de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">2</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Impressão</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Imprimir estatísticas gerais</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">poder ter um relatório geral das vendas</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">2</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Impressão</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Imprimir estatísticas de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">poder ter um relatório de um cliente específico</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">2</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de produtos</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Adicionar um produto</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">poder tê-lo no sistema</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de produtos</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Atualizar o preço de custo de um produto</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">ter um preço atualizado</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de produtos</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Atualizar o preço base de venda de um produto</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">ter um preço atualizado</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de produtos</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">visualizar um produto</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">checar as informações</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Administração de produtos</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Remover um produto</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">não fazer parte do sistema</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">1</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Estatística</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">visualizar as estatísticas de uma carga</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">ter insights sobre as vendas,controle.</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">3</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Estatística</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">visualizar as estatísticas de um cliente</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">ter insights,controle sobre um cliente.</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">3</span>

</td>

</tr>

<tr class="c18">

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Relatório</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">Proprietário</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">visualizar o relatório da carga atual</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">ter noção/controle sobre os pedidos a serem comprados na carga</span>

</td>

<td class="c14" colspan="1" rowspan="1">

<span class="c7">2</span>

</td>

</tr>

</tbody>

</table>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

# <span class="c31 c23 c12">4. Backlog</span>

<span class="c5"></span>

<span class="c5"></span>

## <span class="c24 c23 c12">4.1. Serviço de Administração de clientes(CRUD)</span>

<span class="c9">Funcionalidade 1.1 – Criar Cliente:</span><span class="c5"> Verifica se há algum cliente com o mesmo nome de usuário,autoriza ou não a criação de um novo cliente,se autorizado cria o cliente.</span>

<span class="c9">Funcionalidade 1.2 – Visualizar Cliente:</span><span class="c5"> Permite visualizar os dados de cadastro,os produtos comprados por carga, e estatísticas de um cliente cadastrado.</span>

<span class="c9">Funcionalidade 1.3 – Editar Cliente:</span><span class="c5"> Disponibiliza campos editáveis e autoriza ou não a mudança dos mesmos,também disponibiliza a tabela da carga atual do respectivo cliente para atualização..</span>

<span class="c9">Funcionalidade 1.4 – Apagar Cliente</span><span class="c35">:</span><span class="c5"> Efetiva a exclusão da conta de um cliente.</span>

<span class="c5"></span>

## <span class="c24 c23 c12">4.2. Serviço de Impressão</span>

<span class="c9">Funcionalidade 1.1 –  Imprimir tabela gerada:</span> <span class="c5">disponibiliza a opção de impressão de qualquer tabela gerada,e também dos dados cadastrais de um cliente</span>

<span class="c13 c35"></span>

## <span class="c24 c23 c12">4.3. Serviço de Administração de produtos(CRUD)</span>

<span class="c9">Funcionalidade 1.1 – Criar Produto:</span><span class="c5"> Verifica se há algum produto com o mesmo nome de usuário,autoriza ou não a criação de um novo produto,se autorizado cria o produto.</span>

<span class="c9">Funcionalidade 1.2 – Visualizar Produto:</span><span class="c5"> Permite visualizar os dados de um produto cadastrado.</span>

<span class="c9">Funcionalidade 1.3 – Editar Produto:</span> <span class="c5">possibilidade de atualizar os produtos cadastrados através de um arquivo .xls de notas fiscais do local onde os produtos são adquiridos,também deverá ser possível atualizar um produto inserindo dados pelo teclado.</span>

<span class="c9">Funcionalidade 1.4 – Apagar Cliente</span><span class="c35">:</span><span class="c5"> Efetiva a exclusão de um produto.</span>

<span class="c5"></span>

### <span class="c23 c12 c31">4.4. Serviço de Estatística</span>

<span class="c9">Funcionalidade 1.1 - Estatísticas de todos os clientes :</span><span class="c35"> </span><span class="c5">Deverá mostrar os clientes que mais compram,a região que mais comprou,os cliente que não compram há mais de 2 cargas.os produtos mais comprados e os menos comprado.</span>

<span class="c9">Funcionalidade 1.2 - Estatística por cliente :</span><span class="c35"> </span><span class="c5">Deverá mostrar os produtos mais comprados e os menos comprados,a última carga que o cliente comprou.</span>

<span class="c9">Funcionalidade 1.2- Histórico de compras :</span><span class="c5"> Deverá mostrar todas as compras de um cliente por carga.</span>

<span class="c5"></span>

### <span class="c23 c12 c31">4.5 Serviço de Relatório</span>

<span class="c35">Funcionalidade 1.1 - Elaboração de relatório geral :</span> <span class="c5">Cria um relatório em forma de tabela com a soma dos produtos a serem comprados na carga, o relatório poderá ser de uma região específica(cidade),composição de regiões,ou de todas as regiões,o relatório terá que levar em conta os produtos encontrados no estoque.</span>

<span class="c5"></span>

# <span class="c31 c23 c12">5. Storyboard</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span style="overflow: hidden; display: inline-block; margin: 0.00px 0.00px; border: 0.00px solid #000000; transform: rotate(0.00rad) translateZ(0px); -webkit-transform: rotate(0.00rad) translateZ(0px); width: 699.56px; height: 393.50px;">![](images/image7.jpg)</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span style="overflow: hidden; display: inline-block; margin: -36.25px 36.25px; border: 0.00px solid #000000; transform: rotate(4.71rad) translateZ(0px); -webkit-transform: rotate(4.71rad) translateZ(0px); width: 624.00px; height: 696.50px;">![](images/image4.jpg)</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span style="overflow: hidden; display: inline-block; margin: -29.25px 29.25px; border: 0.00px solid #000000; transform: rotate(4.71rad) translateZ(0px); -webkit-transform: rotate(4.71rad) translateZ(0px); width: 624.00px; height: 682.50px;">![](images/image5.jpg)</span>

<span class="c5"></span>

<span class="c5"></span>

<span style="overflow: hidden; display: inline-block; margin: -24.75px 24.75px; border: 0.00px solid #000000; transform: rotate(4.71rad) translateZ(0px); -webkit-transform: rotate(4.71rad) translateZ(0px); width: 624.00px; height: 673.50px;">![](images/image1.jpg)</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

# <span class="c31 c23 c12">6. Cronograma</span>

<span class="c5"></span>

<span class="c5">        O desenvolvimento do software divide-se em três sprints, todas com duração de 10 dias.</span>

<span class="c5">        A sprint 1 implementará o serviço de administração de clientes e o serviço de administração de produtos A sprint 2 implementará o serviço de impressão e o serviço de relatório, a sprint 3 implementará o serviço de estatística.</span>

<span class="c5"></span>

## <span class="c13 c12">6.1 Data das sprints</span>

<span class="c5"></span>

<span class="c5">Sprint 1 (01/01/19 á 10/01/19)</span>

<span class="c5">Sprint 2 (11/10/19 á 20/01/19)</span>

<span class="c5">Sprint 3(21/01/19 à 31/01/19)</span>

<span class="c5"> </span>

# <span class="c31 c23 c12">7. Requisitos Não Funcionais</span>

## <span class="c23 c12 c24">7.1. Usabilidade</span>

1.  <span class="c23"> Nível de habilidade do usuário</span><span class="c5"> – O sistema deve ser o mais intuitivo e simples possível a fim de minimizar o tempo de uso.</span>

<span class="c5"></span>

## <span class="c24 c23 c12">7.2. Confiabilidade</span>

1.  <span class="c23">Disponibilidade</span><span class="c5"> – O sistema deve estar disponível 24 horas por dia, 7 dias por semana.</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

## <span class="c24 c23 c12">7.3. Portabilidade</span>

1.  <span class="c5">Linguagem de programação: C++,Framework QT</span>
2.  <span class="c5">Sistema Operacional: Windows</span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<span class="c5"></span>

<div>

<span class="c5"></span>

<a id="t.15f80257f11a6853e0ced17865c734453f0fefc8"></a><a id="t.2"></a>

<table class="c52">

<tbody>

<tr class="c18">

<td class="c27" colspan="1" rowspan="1">

<span>Restrito</span>

</td>

<td class="c27" colspan="1" rowspan="1">

<span class="c51">©</span><span class="c5">GeriFácil, 2018</span>

</td>

<td class="c27" colspan="1" rowspan="1">

<span>Página</span>

</td>

</tr>

</tbody>

</table>

<span class="c5"></span>

</div>
