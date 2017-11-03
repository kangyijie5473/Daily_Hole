package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLEncoder;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Created by yangbodong on 2017/10/31.
 */
@WebServlet(name = "ServletLoginFirst" , urlPatterns = "/loginfirst")
public class ServletLoginFirst extends HttpServlet {
    protected void doPost(HttpServletRequest request,
                          HttpServletResponse response)
        throws ServletException, IOException {

        String URL = "https://sso.xiyoulinux.org/oauth/authorize";
        Map<String ,String> urlMap = new HashMap<String, String>();
        urlMap.put("response_type","code");
        urlMap.put("client_id","spider");
        urlMap.put("redirect_uri", URLEncoder.encode("http://localhost:8080/login/"));
        urlMap.put("state","abcdefghijklmnopqrstuvwxzyabcdef");
        urlMap.put("scope","all");

        String url = URL + "?";
        for (String key : urlMap.keySet()) {
            url += key;
            url += "=";
            url += urlMap.get(key);
            url += "&";
        }
        url = url.substring(0, url.length()-1);

        response.sendRedirect(url);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        doPost(request ,response);
    }
}
