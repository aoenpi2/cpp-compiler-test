# 2020.4.26 作成
FROM ubuntu
RUN apt-get update && apt-get install -y build-essential
ENV PATH $PATH:./